#ifndef CTCPSERVER_H
#define CTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

typedef QMap< QString, QTcpSocket* > QTCPMap;

class CTCPServer : public QObject
{
    Q_OBJECT
public:
    explicit CTCPServer(QObject *parent = nullptr);
    virtual ~CTCPServer() override;


protected slots:
    void onNewConnection();
    void onNewMsgReadyRead();

private:
    void init();
    void initConnections();

private:
    QTcpServer           m_tcpServer;
    QTCPMap              m_socketsMap;
    QString              m_serverAddr = "";
    quint16              m_serverPort = 10086;

};

#endif // CTCPSERVER_H
