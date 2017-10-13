#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::buttonPushed);
    connect(ui->inputChangeButton, &QPushButton::clicked, this, &MainWindow::changeInputPath);


}

void MainWindow::buttonPushed()
{
//    DBManager *db = new DBManager;
//    QString query;
//    query = "INSERT INTO test(id,name) VALUES(2,\"PoopyPants\")";
//    qDebug() << query;
//    db->insertData(query);
//    delete db;

    excelparser parse = excelparser();
    qDebug() << "have i even got this far?";

    parse.testRead();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeInputPath()
{
    QString path = QFileDialog::getOpenFileName(this,
                                 tr("Change Input File"),
                                 QApplication::applicationDirPath(),
                                 tr("*.xlsx"));

    if(!path.isEmpty())
    {
        ui->inputPathLabel->setText(path);
        //I dont ahve a settings file... yet
        //settings.setValue("filePaths/inputFilePath", path);
    }
}
