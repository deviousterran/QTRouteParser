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
//    DBManager *db = new DBManager;
//    QString query;
//    query = "INSERT INTO test(id,name) VALUES(2,\"ANDREw Demerast\")";
//    qDebug() << query;
//    db->insertData(query);
//    delete db;


    QStringList args;
    QDir path;
    path.currentPath();

    args << path.currentPath()+ "\\XlsToCsv.vbs" << path.currentPath()+"\\input_headers4_DAN.xlsx" << path.currentPath()+"\\test.csv";
    QProcess process;
//    qDebug() << args;
//    process.setArguments(args);
//    process.setProgram("cmd.exe");
    process.start("cmd.exe", args);
    if (process.waitForStarted())
    {
       process.waitForFinished();
       qDebug() << process.readAllStandardOutput();
    }
    else
       qDebug() << "Failed to start";

    //process.start(path.currentPath() + "/XlsToCsv.vbs input_headers4_DAN.xlsx test.csv");




    CSVimporter *import = new CSVimporter;
    import->csvImportTester1();

}

MainWindow::~MainWindow()
{
    delete ui;
}
