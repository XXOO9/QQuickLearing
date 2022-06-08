#include "CMessageClient.h"

CMessageClient::CMessageClient(QObject *parent) : QObject(parent)
{
    initNetwork();

}

void CMessageClient::connectToServer()
{
    m_pSocket->connectToHost( AddressConfig::serverAddress, AddressConfig::serverPort );
}

void CMessageClient::sendMsg(QString &content)
{
    if( nullptr == m_pSocket ){
        initNetwork();
    }

    m_pSocket->write( content.toLocal8Bit() );
}

void CMessageClient::initNetwork()
{
    if( nullptr == m_pSocket ){
        m_pSocket = new QTcpSocket( this );
    }

    connect( m_pSocket, &QTcpSocket::readyRead, this, &CMessageClient::onNewMsgAvailable );
    initConenction();
    qDebug() << "init client successs...";
}

void CMessageClient::initConenction()
{
    connect( m_pSocket, &QTcpSocket::connected, this, &CMessageClient::onConnectedServerSuccess );
}

void CMessageClient::onNewMsgAvailable()
{
    QString content = QString::fromLocal8Bit( m_pSocket->readAll() );
    qDebug() << "recv from server " << m_pSocket->peerAddress();
}

void CMessageClient::onConnectedServerSuccess()
{
    qDebug() << "connect to server successs...";
}
