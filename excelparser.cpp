#include "excelparser.h"


excelparser::excelparser()
{



}

void excelparser::testRead(){
    libxl::Book* book = xlCreateBook();

    QString file = QDir::currentPath()+ "input_headers4_DAN.xlsx";
    QByteArray BAFile = file.toLocal8Bit();
    const char *cFile = BAFile.constData();

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
                 qDebug() << "row: " << row << " col: " << col <<" contents: "   << sheet->readStr(row,col);
               }

            }
        }

    }else{
        qDebug() << "LibXL error: " << book->errorMessage();
    }
    book->release();


}
