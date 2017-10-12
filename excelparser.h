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
    void testRead();
    QDate makeDate(int day, int month, int year);



};

#endif // EXCELPARSER_H
