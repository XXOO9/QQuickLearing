#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testFunc();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testFunc()
{
#ifdef QT_DEBUG
    qDebug() << QString::fromLocal8Bit( "嘞是 debug 模式" );
#else
    qDebug() << QString::fromLocal8Bit( "嘞是 release 模式" );
#endif
}
