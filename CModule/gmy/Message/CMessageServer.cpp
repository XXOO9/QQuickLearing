#include "CMessageServer.h"

CMessageServer::CMessageServer(QObject *parent) : QObject(parent)
{
    initServer();
    isServer();
    initLog();
    currentTime();
}

void CMessageServer::closeServer()
{
}

void CMessageServer::writeLog(QString &content)
{
    if( nullptr == m_pFileWriter ){
        return;
    }
    content = currentTime() + "\n" + content + "\n\n";
    m_pFileWriter->write( content.toLocal8Bit() );
    m_pFileWriter->flush();
}

QString CMessageServer::currentTime()
{
    QString dateTime = QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" );
    return dateTime;
}

void CMessageServer::initServer()
{
    if( nullptr == m_pServer ){
        m_pServer = new QTcpServer( this );
    }

    QHostAddress hostAddress;
    hostAddress.setAddress( AddressConfig::serverAddress );
    bool ok = m_pServer->listen( hostAddress, AddressConfig::serverPort );

    if( !ok ){
        qDebug() << "listen failed, errorString = " << m_pServer->errorString();
        return;
    }

    initConnection();

    qDebug() << "init server success...";


}

void CMessageServer::initLog()
{
    QString fileName = QCoreApplication::applicationDirPath();

    if( nullptr == m_pFileWriter ){
        fileName += "/logInfo.txt";
        m_pFileWriter = new QFile( fileName, this );
    }

    if( !m_pFileWriter->open( QIODevice::ReadWrite ) ){
        qDebug() << "open log file failed...";
        return;
    }
}

void CMessageServer::initConnection()
{
    connect( m_pServer, &QTcpServer::newConnection, this, &CMessageServer::onNewConnectionAvailable );
}

bool CMessageServer::isServer()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for( auto &eachEle: list ){
        if( eachEle.toIPv4Address() ){
            if( eachEle.toString().contains( AddressConfig::serverAddress ) ){
                return true;
            }
        }
    }

    return false;
}

void CMessageServer::onNewConnectionAvailable()
{
    QTcpSocket  *newSocket = m_pServer->nextPendingConnection();
    QString address = newSocket->peerAddress().toString();
    QString peerName = newSocket->peerName();
    QString peerPort = newSocket->peerPort();

    QString logInfo = "new connection, addr = " + address;
    writeLog( logInfo );

    m_mapSockets.insert( address, newSocket );

    connect( newSocket, &QTcpSocket::readyRead, [=](){
        QString address = newSocket->peerAddress().toString();
        qDebug() << "recv msg from " << address;
        QString content = QString::fromLocal8Bit( newSocket->readAll() );
        qDebug() << "msg = " << content;
        writeLog( content );
    });
}

void CMessageServer::onNewMsgReadyRead()
{

}
