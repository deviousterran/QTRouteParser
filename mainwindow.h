#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include <QtCore>
#include "csvimporter.h"
#include <QProcess>
#include <QStringList>
#include "excelparser.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void buttonPushed();
    ~MainWindow();

public slots:
    void changeInputPath();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
