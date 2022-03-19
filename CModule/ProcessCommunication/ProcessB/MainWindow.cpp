#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initClient();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initClient()
{
    connect( ui->pushButton, &QPushButton::clicked, [=](){
        QString content = ui->textEdit->toPlainText();
        if( content.isEmpty() || content.isNull() ){
            return;
        }
        ui->textEdit->clear();
        sendMsgToServer( content );
    });
    m_pSocket = new QLocalSocket( this );
    connect( m_pSocket, &QLocalSocket::readyRead, this, &MainWindow::onNewMsgAvailable );
    m_pSocket->connectToServer( "WDNMD" );
}

void MainWindow::sendMsgToServer(QString msg)
{
    if( nullptr == m_pSocket ){
        return;
    }

    m_pSocket->write( msg.toUtf8() );
}

void MainWindow::onNewMsgAvailable()
{
    QString msg = QString::fromUtf8( m_pSocket->readAll() );
    qDebug() << "recv msg = " << msg;
    ui->textBrowser->append( msg );
}
