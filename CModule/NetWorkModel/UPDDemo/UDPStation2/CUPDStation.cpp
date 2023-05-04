#include "CUPDStation.h"

CUPDStation::CUPDStation(QObject *parent) : QObject(parent)
{
    init();
    test();
}

void CUPDStation::send()
{
    m_pUdpSocket->writeDatagram( "Hello", QHostAddress::LocalHost, 10086 );
}

void CUPDStation::onNewMessage()
{
    QHostAddress address;
    quint16       srcPort = 0;
    QByteArray buffer;
    buffer.resize( m_pUdpSocket->pendingDatagramSize() );

    m_pUdpSocket->readDatagram( buffer.data(), buffer.size(), &address, &srcPort );
    qDebug() << "recv ne msg = " << buffer << " addr = " << address.toString() << " port = " << srcPort;
    QString msg = QString::fromUtf8( "收到了，老表!" );
    m_pUdpSocket->writeDatagram( msg.toUtf8(), address, srcPort );
}

void CUPDStation::init()
{
    if( nullptr == m_pUdpSocket ){
        m_pUdpSocket = new QUdpSocket( this );
    }

    bool ok = m_pUdpSocket->bind( QHostAddress::LocalHost, 10085 );
    qDebug() << "station 2 bind ret = " << QVariant( ok );
    connect( m_pUdpSocket, &QUdpSocket::readyRead, this, &CUPDStation::onNewMessage );
}

void CUPDStation::test()
{
    QJsonObject jsobj;

    QJsonObject js1{ { "property1", 1} };
    QJsonObject js2{ { "property2", 2} };

    QJsonArray jsArray;
    jsArray << js1 << js2;

    jsobj.insert( "WDNMD", jsArray );

    qDebug() << "json = " << jsobj;
}
