#ifndef CMESSAGESERVER_H
#define CMESSAGESERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QList>
#include <QDebug>
#include <QNetworkInterface>
#include <QFile>
#include <QCoreApplication>
#include <QDateTime>

#include "CMessageCommonConfig.h"

class CMessageServer : public QObject
{
    Q_OBJECT
public:
    explicit CMessageServer(QObject *parent = nullptr);

    void closeServer();
    void writeLog( QString &content );


public:
    static QString currentTime();

private:
    void initServer();
    void initLog();
    void initConnection();
    bool isServer();

signals:

public slots:
    void onNewConnectionAvailable();
    void onNewMsgReadyRead();

private:
    QTcpServer                     *m_pServer = nullptr;
    QMap< QString, QTcpSocket* >    m_mapSockets;
    QFile                          *m_pFileWriter = nullptr;
};

#endif // CMESSAGESERVER_H
