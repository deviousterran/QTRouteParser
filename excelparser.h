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


class excelparser
{
public:
    excelparser();
    excelparser(QString filepath);
    void testRead();
    QDate makeDate(int day, int month, int year);


    QString file;


};

#endif // EXCELPARSER_H
