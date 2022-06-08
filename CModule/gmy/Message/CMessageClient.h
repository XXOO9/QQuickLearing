#ifndef CMESSAGECLIENT_H
#define CMESSAGECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QList>
#include <QDebug>

#include "CMessageCommonConfig.h"

class CMessageClient : public QObject
{
    Q_OBJECT
public:
    explicit CMessageClient(QObject *parent = nullptr);

    void connectToServer();
    void sendMsg( QString &content );
private:
    void initNetwork();
    void initConenction();

public slots:
    void onNewMsgAvailable();
    void onConnectedServerSuccess();

private:
    QTcpSocket  *m_pSocket = nullptr;
};

#endif // CMESSAGECLIENT_H
