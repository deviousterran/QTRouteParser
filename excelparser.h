#ifndef EXCELPARSER_H
#define EXCELPARSER_H


#pragma once
#include <QString>
#include <QDate>
#include <QDialog>
#include <QMessageBox>
#include "libxl.h"
#include <QDir>
#include <QDebug>
#include <QVector>

class excelparser
{
public:
    excelparser();
    excelparser(QString filepath);

    libxl::Book * book;


    QVector<QStringList> restult;


    QString getFilePath();
    void setFilePath(QString file);
    QVector<QStringList> getResult();
    void clearResult();
    void testRead();
    QDate makeDate(int day, int month, int year);

private:
    QString filePath;
    const char * cFile;
    const char tempChar;
};

#endif // EXCELPARSER_H
