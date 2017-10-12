#include "dbmanager.h"
#include <QtCore>




DBManager::DBManager(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase(_DRIVER);
    db.setDatabaseName(_PATH);
    createTable();
}

QString DBManager::OutputPath(){
    return _PATH;
}

void DBManager::openDB(){
    if(!db.open())
        qWarning() << "ERROR: " << db.lastError();
}

void DBManager::closeDB(){
    db.close();
}
void DBManager::createTable(){
    openDB();
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, name TEXT)");
    if(query.exec()){
    }else{
        qDebug() << "table creation error:"
               << query.lastError();
    }
    closeDB();
}

bool DBManager::insertData(QString queryString){
    bool success = false;
    QSqlQuery query;
    openDB();
    query.prepare(queryString);
    if(query.exec()){
        success = true;
        qDebug() << "Successful Query";
    }else{
        qWarning() << "data insertion error1: "
               << query.lastError();
        qDebug() << query.lastQuery();
    }
    closeDB();
    return success;
}

bool DBManager::insertData(QSqlQuery query){
    bool success = false;
    qDebug() << query.lastQuery();
    openDB();
    if(query.exec()){
        success = true;
        qDebug() << "Successful Query";
    }else{
        qWarning() << "data insertion error2: "
               << query.lastError();
        qDebug() << query.lastQuery();
    }
    closeDB();
    return success;

}
