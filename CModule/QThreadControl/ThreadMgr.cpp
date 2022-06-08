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
    m_pPrintThread->killThread();
}

void ThreadMgr::timerControler()
{
    m_pPrintThread->stopTimer();
}

void ThreadMgr::deletePrinter()
{
    if( nullptr != m_pPrintThread ){
        m_pPrintThread->deleteLater();
        m_pPrintThread = nullptr;
    }
}
