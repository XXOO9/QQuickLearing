#include "CViewManager.h"

CViewManager::CViewManager(QObject *parent) : QObject(parent)
{
    initNetwork();
}

void CViewManager::sendMsg(QString content)
{
    m_pClient->sendMsg( content );
}

void CViewManager::connectedToServer()
{
    m_pClient->connectToServer();
}


void CViewManager::initNetwork()
{
    m_pClient = new CMessageClient( this );
    m_pServer = new CMessageServer( this );
}
