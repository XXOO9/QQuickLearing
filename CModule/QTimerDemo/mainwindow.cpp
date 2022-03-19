#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTimer()
{
    m_timer.setInterval( 2000 );
    int i = 0;
    connect( &m_timer, &QTimer::timeout, [=](){
        qDebug() << "time out ";
    });
    m_timer.start();
}
