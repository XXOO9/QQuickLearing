#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pLocalServer( nullptr ),
    m_pSocket( nullptr )
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    m_process.terminate();
    delete ui;
}

void MainWindow::init()
{
    if( nullptr == m_pLocalServer ){
        m_pLocalServer = new QLocalServer( this );
    }

    connect( m_pLocalServer, &QLocalServer::newConnection, this, &MainWindow::onNewConnection );
    connect( ui->pushButton, &QPushButton::clicked, [=](){
        QString content = ui->textEdit->toPlainText();
        ui->textEdit->toPlainText().clear();
        sendToClient( content );
    });

    m_pLocalServer->listen( "WDNMD" );

    satrtExcute();
}

void MainWindow::sendToClient(QString msg)
{
    if( nullptr == m_pSocket ){
        return;
    }

    m_pSocket->write( msg.toUtf8() );
}

bool MainWindow::satrtExcute()
{
    QString exePath = "../../ProcessB/debug/ProcessB.exe";

    m_process.start( exePath );
    return true;
}

void MainWindow::onNewConnection()
{
    qDebug() << "server msg:: new connection";
    m_pSocket = m_pLocalServer->nextPendingConnection();

    if( nullptr != m_pSocket && (QAbstractSocket::ConnectedState == m_pSocket->state() ) ){
        connect( m_pSocket, &QLocalSocket::readyRead, this, &MainWindow::onReadyRead );
    }
}

void MainWindow::onReadyRead()
{
    QByteArray recv = m_pSocket->readAll();
    QString recvString = QString::fromUtf8( recv );
    qDebug() << "recv from client msg = " << recvString;
}
