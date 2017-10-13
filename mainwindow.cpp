#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::buttonPushed);
    connect(ui->inputChangeButton, &QPushButton::clicked, this, &MainWindow::changeInputPath);

    parse.file = QDir::currentPath()+ "/upload week 1.xlsx";

    ui->inputPathLabel->setText(parse.file);
}

void MainWindow::buttonPushed()
{
//    DBManager *db = new DBManager;
//    QString query;
//    query = "INSERT INTO test(id,name) VALUES(2,\"PoopyPants\")";
//    qDebug() << query;
//    db->insertData(query);
//    delete db;

    parse.testRead();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeInputPath()
{
    parse.file = QFileDialog::getOpenFileName(this,
                                 tr("Change Input File"),
                                 QApplication::applicationDirPath(),
                                 tr("*.xlsx"));

    if(!parse.file.isEmpty())
    {
        ui->inputPathLabel->setText(parse.file);
        //I dont ahve a settings file... yet
        //settings.setValue("filePaths/inputFilePath", path);
    }
}
