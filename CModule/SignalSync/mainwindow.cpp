#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->pushButton, &QPushButton::clicked, this, &MainWindow::callFunc );
    initConnection();
    m_timer.setInterval( 5000 );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initConnection()
{
    connect( &m_timer, &QTimer::timeout, this, &MainWindow::onTimeout, Qt::QueuedConnection );
    connect( this, &MainWindow::sigStartTimer, this, &MainWindow::onStartTimer, Qt::QueuedConnection );
}

void MainWindow::startEmitSig()
{
    qDebug() << "start emit sig...";
    emit sigStartTimer();
    qDebug() << "emit sig finished...";
}

void MainWindow::callFunc()
{
    startEmitSig();
    qDebug() << "WDNMD";
}

void MainWindow::onTimeout()
{
    qDebug() << "time out...";
}

void MainWindow::onStartTimer()
{
    qDebug() << "start timer";
    m_timer.start();
}
