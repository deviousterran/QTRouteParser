#include "excelparser.h"


excelparser::excelparser()
{



}

void excelparser::testRead(){
    libxl::Book* book = xlCreateXMLBook();

    QString file = QDir::currentPath()+ "/input_headers4_DAN.xlsx";
    QByteArray BAFile = file.toLocal8Bit();
    const char *cFile = BAFile.constData();
    QStringList inputReader;
    QStringListIterator inputReaderIter(inputReader);

    qDebug() << file;
    book->setKey("Andrew Demarest", "windows-2e29230504caec046ab06b6aa6s4g6uf");

    if(book->load(cFile))
    {

        libxl::Sheet* sheet = book->getSheet(0);
        if(sheet)
        {
            for(int row = sheet->firstRow(); row < sheet->lastRow(); ++row)
            {
               for(int col = sheet->firstCol(); col < sheet->lastCol(); ++col)
               {
                   if (col == 4|| col == 8){
                       int day,month,year;
                       book->dateUnpack(sheet->readNum(row,col),&year,&month,&day);
                       inputReader << makeDate(day,month,year).toString("M/d/yyyy");

                   }else{
                       inputReader << sheet->readStr(row,col);
                   }

               }
                qDebug() << inputReader.size() << "this is the string reader size";
                foreach(QString str, inputReader){
                    qDebug() << "value:" << str;
                }

               inputReader.clear();
            }
        }

    }else{
        qDebug() << "LibXL error: " << book->errorMessage();
    }
    book->release();


}

QDate excelparser::makeDate(int day, int month, int year){
    QDate temp(year,month,day);
    return temp;
}
