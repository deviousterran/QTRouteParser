#include "excelparser.h"


excelparser::excelparser()
{
    file = QDir::currentPath()+ "/upload week 1.xlsx";
    qDebug() << "called default constructor";
}

excelparser::excelparser(QString filepath)
{
    file = filepath;
        qDebug() << "called overloaded constructor";
}


void excelparser::testRead(){
    book = xlCreateXMLBook();

    //converts the QString file path to a const char using these two lines
    QByteArray BAFile = file.toLocal8Bit();
    const char *cFile = BAFile.constData();

    QStringList inputReader;
    QStringListIterator inputReaderIter(inputReader);

    int numberOfElements = 0;

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
                   if (col == 4|| col == 8){//these are the fields with dates in them.  using unpack to get the excel date much faster than trying to manually convert

                       int day,month,year;
                       book->dateUnpack(sheet->readNum(row,col),&year,&month,&day);
                       inputReader << makeDate(day,month,year).toString("M/d/yyyy");

                   }else{

                       inputReader << sheet->readStr(row,col);
                   }

               }
                //qDebug() << inputReader.size() << "this is the string reader size";
                //qDebug() << row;
                restult.append(inputReader);
                inputReader.clear();
            }
        }

    }else{
        qDebug() << "LibXL error: " << book->errorMessage();
    }

    book->release();
    qDebug() << "i read and handeled " << restult.size() << " orders";

}
//quick date creation method... probably pointless
QDate excelparser::makeDate(int day, int month, int year){
    QDate temp(year,month,day);
    return temp;
}
