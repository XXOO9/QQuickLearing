#include "CUPDStation.h"

CUPDStation::CUPDStation(QObject *parent) : QObject(parent)
{
    init();
}

void CUPDStation::send()
{
    m_pUdpSocket->writeDatagram( "Hello", QHostAddress::LocalHost, 10085 );
}

void CUPDStation::onNewMessage()
{
    QHostAddress address;
    quint16       srcPort = 0;
    QByteArray buffer;
    buffer.resize( m_pUdpSocket->pendingDatagramSize() );

    m_pUdpSocket->readDatagram( buffer.data(), buffer.size(), &address, &srcPort );
    qDebug() << "station 1 recv ne msg = " << QString::fromUtf8( buffer ) << " addr = " << address.toString() << " port = " << srcPort;
}

void CUPDStation::init()
{
    if( nullptr == m_pUdpSocket ){
        m_pUdpSocket = new QUdpSocket( this );
    }

    bool ok = m_pUdpSocket->bind( QHostAddress::LocalHost, 10086 );
    qDebug() << "station 1 bind ret = " << QVariant( ok );
    connect( m_pUdpSocket, &QUdpSocket::readyRead, this, &CUPDStation::onNewMessage );
}
