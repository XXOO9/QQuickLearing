#include "ThreadPrint.h"

ThreadPrint::ThreadPrint(QObject *parent) : QObject(parent)
{
    qDebug() << "main threadID = " << QThread::currentThreadId();
    init();

    emit insideStartTimer();
}

ThreadPrint::~ThreadPrint()
{
    bool ok = stopTimer();

    if( m_printThread.isRunning() ){
        m_printThread.quit();
    }
    qDebug() << "start destory thread obj...";
}

void ThreadPrint::startPrint()
{
    m_mutex.lock();
    m_printFlag = true;
    m_mutex.unlock();

    emit insideSigStartPrint();
}

void ThreadPrint::stopThread()
{

    if( !m_printThread.isRunning() ){
        return;
    }

    m_mutex.lock();
    m_printFlag = false;
    m_mutex.unlock();



    if( m_printThread.isRunning() ){
        qDebug() << "GG..";
    }
}

void ThreadPrint::killThread()
{
    stopThread();
    stopTimer();
    m_printThread.quit();

    qDebug() <<" level =  " << m_printThread.loopLevel();
    bool ok = m_printThread.wait();
    ok = m_printThread.isFinished();
    qDebug() << "wait ret = " << ok;
}

bool ThreadPrint::stopTimer()
{
    if( m_timer.isActive() ){
        m_timer.stop();
    }

    return m_timer.isActive();
}

void ThreadPrint::onStartPrint()
{
    qDebug() << "onStartPrint threadID = " << QThread::currentThreadId();
    int i = 0;

    while( true ){
        m_mutex.lock();
        if( !m_printFlag ){
            m_mutex.unlock();
            break;
        }
        m_mutex.unlock();
        qDebug() << "onStartPrint func " << QThread::currentThreadId() << QDateTime::currentDateTime();
        QThread::sleep( 1 );
    }
}

void ThreadPrint::onStartCount()
{
    while( true ){
        qDebug() << "count func " << QThread::currentThreadId();
    }
}

void ThreadPrint::onConnection()
{
    qDebug() << "connection threadID = " << QThread::currentThreadId();
    connect( this, &ThreadPrint::insideSigStartPrint, this, &ThreadPrint::onStartPrint, Qt::QueuedConnection );

    emit insideSigStartPrint();
}

void ThreadPrint::onThreadFinished()
{
    qDebug() << "thread finished...!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
}

void ThreadPrint::onStartTimer()
{
    qDebug() << "start timer ThreadID = " << QThread::currentThreadId();
    m_timer.start( 1000 );
}

void ThreadPrint::onTimerTimeout()
{
    qDebug() << "time out func, " << QThread::currentThreadId();
}

void ThreadPrint::init()
{
    initConnection();

    this->moveToThread( &m_printThread );
    m_timer.moveToThread( &m_printThread );
    m_printThread.start();
    if( m_printThread.isRunning() ){
        qDebug() << "kaishile...";
    }
}

void ThreadPrint::initConnection()
{
    qDebug() << "initConnection threadID = " << QThread::currentThreadId();
    //    connect( this, &ThreadPrint::insideSigInitConnection, this, &ThreadPrint::onConnection );
    connect( this, &ThreadPrint::insideSigStartPrint, this, &ThreadPrint::onStartPrint, Qt::QueuedConnection );
    connect( this, &ThreadPrint::insideSigStartCount, this, &ThreadPrint::onStartCount, Qt::QueuedConnection );
    connect( &m_printThread, &QThread::finished, this, &ThreadPrint::onThreadFinished, Qt::QueuedConnection );
    connect( this, &ThreadPrint::insideStartTimer, this, &ThreadPrint::onStartTimer, Qt::QueuedConnection );
    connect( &m_timer, &QTimer::timeout, this, &ThreadPrint::onTimerTimeout, Qt::QueuedConnection );
}
