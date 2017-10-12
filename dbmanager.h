#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include "dbmanager.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>


class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager(QObject *parent = 0);


    /**
     * @brief db
     * container for the Database
     */

    QString OutputPath();
    bool insertData(QString query);
    bool insertData(QSqlQuery query);
    void openDB();
    void closeDB();
signals:

public slots:


private:
    /**
     * @brief _DRIVER
     * constant for the driver QT uses to access the database
     */
    const QString _DRIVER= "QSQLITE";
    /**
     * @brief _PATH
     * constant for the actual location of the database
     */
    const QString _PATH = databasePath.currentPath()+"route.db";

    QDir databasePath;
    void createTable();
    QSqlDatabase db;

};




#endif // DBMANAGER_H
