#ifndef CVIEWMANAGER_H
#define CVIEWMANAGER_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include "../Message/CMessageServer.h"
#include "../Message/CMessageClient.h"

class CViewManager : public QObject
{
    Q_OBJECT
public:
    explicit CViewManager(QObject *parent = nullptr);


/*******************************所有的测试函数**************************************/
public:

    Q_INVOKABLE void sendMsg( QString content = "hahahahah" );

    Q_INVOKABLE void connectedToServer();


private:
    void initNetwork();

signals:

public slots:

private:
    CMessageClient  *m_pClient = nullptr;
    CMessageServer  *m_pServer = nullptr;
    bool             m_isServer = true;
};

#endif // CVIEWMANAGER_H
