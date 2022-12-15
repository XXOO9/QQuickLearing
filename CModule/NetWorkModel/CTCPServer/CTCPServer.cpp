#include "CTCPServer.h"

CTCPServer::CTCPServer(QObject *parent) : QObject(parent)
{
    init();
}

CTCPServer::~CTCPServer()
{

}

void CTCPServer::onNewConnection()
{
    static int index = 0;
    QTcpSocket  *tmpSocket = m_tcpServer.nextPendingConnection();
    connect( tmpSocket, &QTcpSocket::readyRead, this, &CTCPServer::onNewMsgReadyRead );
    qDebug() << "new connection ip = " << tmpSocket->peerAddress() << " port = " << tmpSocket->peerPort();
    m_socketsMap.insert( QString::number( index++ ), tmpSocket );

    QString recv = QString::fromLocal8Bit( tmpSocket->readAll() );
    tmpSocket = nullptr;
}

void CTCPServer::onNewMsgReadyRead()
{
    for( auto &ele : m_socketsMap ){
        if( ele->isReadable() ){
            qDebug() << "msg = " << QString::fromLocal8Bit( ele->readAll() );
            ele->write( "WDNMD" );
            qDebug() << "replyed...";
        }
    }
}

void CTCPServer::init()
{
    QHostAddress targetHost = QHostAddress( "172.16.16.61" );
    bool ok = m_tcpServer.listen( targetHost, m_serverPort );
    if( !ok ){
        qDebug() << "server listen failed!";
        return;
    }
    initConnections();
    qDebug() << "listen success...";
}

void CTCPServer::initConnections()
{
    connect( &m_tcpServer, &QTcpServer::newConnection, this, &CTCPServer::onNewConnection );
}
