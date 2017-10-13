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
    void testRead();
    QDate makeDate(int day, int month, int year);
    libxl::Book* book;

    QString file;
    QVector<QStringList> restult;



};

#endif // EXCELPARSER_H
