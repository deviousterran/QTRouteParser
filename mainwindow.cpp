#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::buttonPushed);



}

void MainWindow::buttonPushed()
{
    DBManager *db = new DBManager;
    QString query;
    query = "INSERT INTO test(id,name) VALUES(2,\"ANDREw Demerast\")";
    qDebug() << query;
    db->insertData(query);


    delete db;




}

MainWindow::~MainWindow()
{
    delete ui;
}
