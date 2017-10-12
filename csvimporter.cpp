#include "csvimporter.h"


CSVimporter::CSVimporter(QObject *parent) : QObject(parent)
{


}

void CSVimporter::csvImportTester1(){

    QString fileName = "test.csv";
    QFile file(fileName);
    bool skipReadLIne = true;
    QStringList wordList;
    QTextStream ts(&file);
    Order o;
    int lineCount = 0;

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();

    }
    while (!ts.atEnd()) {
        QString lastHeader = "Pft %";
        QString line = ts.readLine();
        //remove any double quotes that Excel formatting adds
        //line.remove(QChar('"')); //don't want to do this, may loose the ability to remove inserted commas from strings
        //splits the line into segmets on a comma
        /*        line.split(',')*/;
        //all csv lines have a extra element on the end, so remove that extra data.
        //line.resize(line.size()-1);
        if(lineCount < 5){
            qDebug() << line;
        }

        if(!skipReadLIne){
            qDebug() << line;
            wordList = line.split(',');
            //qDebug() << "wordlist is: " <<wordList[1];
            //o.setOrderInfo(wordList);;
            //qDebug() << o.getInvoiceDate();
            //line

        }

        if(line == lastHeader){
            skipReadLIne = false;
        }
        lineCount++;
    }

    qDebug() << wordList;








}







void CSVimporter::excelImportTester1(){

    //QString lePath = QFileDialog::getOpenFileName(this, "Open Image", QDir::currentPath(), "Image Files (*.png *.jpg *.bmp)");
    qDebug() << QDir::currentPath();

    QString file = QDir::currentPath() + "/input Tester.xls";
    qDebug() << "Open excel.. \n";
    qDebug() << "file location is: " << file;
    QSqlDatabase excel = QSqlDatabase::addDatabase("QODBC");
    excel.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xls)};DBQ=" + file);


    if(excel.open())
    {
        int cont = 0;
        QSqlQuery query("select * from " + QString("Sheet1")  + "$]");
        qDebug() << query.lastQuery();
        while(query.next())
        {
           QString column1= query.value(0).toString();
           QString column2= query.value(1).toString();
           QString column3= query.value(2).toString();
           QString column4= query.value(3).toString();
           QString column5= query.value(4).toString();

            qDebug("('', %d, %d, %d, \"%s\"),",
                   column2.toInt(),
                   column3.toInt(),
                   column4.toInt(),
                   column5.toStdString().c_str());

            cont++;
        }

        QString reg = "Regs: " + cont;
        qDebug() << reg;

    }
    else
    {
        qDebug() << "Can't open file (Excel)" << endl;
    }

}
void CSVimporter::excelImportTester2(){

    CoInitializeEx(NULL, COINIT_MULTITHREADED);

    QTableWidget tester;
    QString fileName = QDir::currentPath() + "/input Tester.xls";

    QAxObject* excel = new QAxObject( "Excel.Application", 0 );
    QAxObject* workbooks = excel->querySubObject( "Workbooks" );
    QAxObject* workbook = workbooks->querySubObject( "Open(const QString&)", fileName );
    QAxObject* sheets = workbook->querySubObject( "Worksheets" );
    int sheetCount = sheets->dynamicCall("Count()").toInt();        //worksheets count
    QAxObject* sheet = sheets->querySubObject( "Item( int )", 0 );

    // Find the cells that actually have content
    QAxObject* usedrange = sheet->querySubObject( "UsedRange");
    QAxObject * rows = usedrange->querySubObject("Rows");
    QAxObject * columns = usedrange->querySubObject("Columns");
    int intRowStart = usedrange->property("Row").toInt();
    int intColStart = usedrange->property("Column").toInt();
    int intCols = columns->property("Count").toInt();
    int intRows = rows->property("Count").toInt();

    // replicate the Excel content in the QtableWidget
    tester.setColumnCount(intColStart+intCols);
    tester.setRowCount(intRowStart+intRows);
    for (int row=intRowStart ; row < intRowStart+intRows ; row++) {
        for (int col=intColStart ; col < intColStart+intCols ; col++) {
            QAxObject* cell = sheet->querySubObject( "Cells( int, int )", row, col );

            QVariant value = cell->dynamicCall( "Value()" );
            qDebug() << value << ",";
            if (value.toString().isEmpty())
                continue;

            QTableWidgetItem * twi = new QTableWidgetItem(value.toString());
            tester.setItem(row-1, col-1, twi);
        }
        qDebug() << "\n";
    }

    // clean up and close up
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");
}
