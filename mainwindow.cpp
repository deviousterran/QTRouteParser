#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::buttonPushed);
    connect(ui->inputChangeButton, &QPushButton::clicked, this, &MainWindow::changeInputPath);
    //when i add a settings file, this will be the last used location or the user directory
    parse.setFilePath(QDir::currentPath()+ "/upload week 1.xlsx");

    ui->inputPathLabel->setText(parse.getFilePath());
}

void MainWindow::buttonPushed()
{
    //cruft for testing database ussage.  I'm not going to do any database stuff here, the order class will do it
//    DBManager *db = new DBManager;
//    QString query;
//    query = "INSERT INTO test(id,name) VALUES(2,\"PoopyPants\")";
//    qDebug() << query;
//    db->insertData(query);
//    delete db;

    parse.testRead();
    parse.clearResult();//clear vector and release memory immediately
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeInputPath()
{
    parse.setFilePath(QFileDialog::getOpenFileName(this,
                                 tr("Change Input File"),
                                 QApplication::applicationDirPath(),
                                 tr("*.xlsx")));

    if(!parse.getFilePath().isEmpty())
    {
        ui->inputPathLabel->setText(parse.getFilePath());
        //I dont ahve a settings file... yet
        //settings.setValue("filePaths/inputFilePath", path);
    }
}
