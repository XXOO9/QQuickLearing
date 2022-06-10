#include "ThreadMgr.h"

ThreadMgr::ThreadMgr(QObject *parent) : QObject(parent)
{
    m_pPrintThread = new ThreadPrint();
}

ThreadMgr::~ThreadMgr()
{
    qDebug() << "WDNMD;";
}

void ThreadMgr::startPrint()
{
    m_pPrintThread->startPrint();
}

void ThreadMgr::stopThread()
{
    m_pPrintThread->stopThread();
}

void ThreadMgr::killThread()
{
//    m_pPrintThread->onKillThread();
}

void ThreadMgr::timerControler( bool ok )
{
    if( ok ){
        emit m_pPrintThread->insideStartTimer();
    }else{
        m_pPrintThread->stopTimer();
    }
}

void ThreadMgr::deletePrinter()
{
    if( nullptr != m_pPrintThread ){
//        emit m_pPrintThread->insideSigKillThread();
        m_pPrintThread->printThread()->exit();
        m_pPrintThread->deleteLater();
        m_pPrintThread = nullptr;
    }
}
