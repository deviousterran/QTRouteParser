#ifndef CSVIMPORTER_H
#define CSVIMPORTER_H
#pragma once
#include <QtCore>
#include <QtWidgets>
#include <QObject>
#include <QFile>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QAxObject>
#include <QTableWidget>
#include <QTableView>
#include "order.h"



class CSVimporter : public QObject
{
    Q_OBJECT
private: 
        QString _PATH = "";
        

public:
    explicit CSVimporter(QObject *parent = nullptr);
    void openFile();
    void excelImportTester1();
    void excelImportTester2();
    void csvImportTester1();
    
    QFile *csvFile();
    
signals:

public slots:
    
    
};

#endif // CSVIMPORTER_H
