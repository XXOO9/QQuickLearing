#include "CTCPClient.h"

CTCPClient::CTCPClient(QObject *parent) : QObject(parent)
{
    init();

    connectTargetServer();
}

void CTCPClient::init()
{
    if( nullptr == m_pTcpSocket ){
        m_pTcpSocket = new QTcpSocket( this );
    }

    initConnections();
}

void CTCPClient::initConnections()
{
    connect( m_pTcpSocket, &QTcpSocket::connected, this, &CTCPClient::onConnected );
}

void CTCPClient::connectTargetServer()
{
    qDebug() << "start connect server...";
    m_pTcpSocket->connectToHost( "127.0.0.1", 10086 );
}

void CTCPClient::onConnected()
{
    qDebug() << "socket connecte success...";
}
