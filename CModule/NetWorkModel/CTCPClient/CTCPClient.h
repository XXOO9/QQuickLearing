#ifndef CTCPCLIENT_H
#define CTCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class CTCPClient : public QObject
{
    Q_OBJECT
public:
    explicit CTCPClient(QObject *parent = nullptr);
private:
    void init();
    void initConnections();

    void connectTargetServer();
protected slots:
    void onConnected();
private:
    QTcpSocket  *m_pTcpSocket = nullptr;
};

#endif // CTCPCLIENT_H
