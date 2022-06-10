#include "ThreadPrint.h"

ThreadPrint::ThreadPrint(QObject *parent) : QObject(parent)
{
    qDebug() << "main threadID = " << QThread::currentThreadId();
    init();

}

ThreadPrint::~ThreadPrint()
{
    qDebug() << "destory func Thread ID = " << QThread::currentThreadId();
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

    if( !m_printThread->isRunning() ){
        return;
    }

    m_mutex.lock();
    m_printFlag = false;
    m_mutex.unlock();



    if( m_printThread->isRunning() ){
        qDebug() << "GG..";
    }
}

void ThreadPrint::onKillThread()
{
    stopThread();
//    stopTimer();
    m_printThread->quit();

    qDebug() <<" level =  " << m_printThread->loopLevel();
    bool ok = false;
    ok = m_printThread->isFinished();

    if( m_printThread->isRunning() ){
        qDebug() << "still running...";
    }
    qDebug() << "wait ret = " << ok;
}

bool ThreadPrint::stopTimer()
{
    if( m_timer->isActive() ){
        m_timer->stop();
        qDebug() << "stop timer ThreadID = " <<QThread::currentThreadId();
    }

    return m_timer->isActive();
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
    if( nullptr != m_printThread ){
        m_printThread->deleteLater();
        m_printThread = nullptr;
    }
}

void ThreadPrint::onStartTimer()
{
    qDebug() << "start timer ThreadID = " << QThread::currentThreadId();
    m_timer->start( 1000 );
}

void ThreadPrint::onTimerTimeout()
{
    qDebug() << "time out func, " << QThread::currentThreadId();
}

void ThreadPrint::init()
{
    m_printThread = new QThread();
    connect( m_printThread, &QThread::started, [=](){
        qDebug() << "on start ThreadID = " << QThread::currentThreadId();
        m_timer = new QTimer( this );
        initConnection();
        if( m_printThread->isRunning() ){
            qDebug() << "kaishile...";
        }
    });
    this->moveToThread( m_printThread );

    //这个信号一定要在start之前连接!!!!!!!!!!!
    connect( m_printThread, &QThread::finished, this, &ThreadPrint::onThreadFinished );
    m_printThread->start();
}

void ThreadPrint::initConnection()
{
    qDebug() << "initConnection threadID = " << QThread::currentThreadId();
    connect( this, &ThreadPrint::insideSigStartPrint, this, &ThreadPrint::onStartPrint, Qt::QueuedConnection );
    connect( this, &ThreadPrint::insideSigStartCount, this, &ThreadPrint::onStartCount, Qt::QueuedConnection );
    connect( m_printThread, &QThread::finished, this, &ThreadPrint::onThreadFinished, Qt::QueuedConnection );
    connect( this, &ThreadPrint::insideStartTimer, this, &ThreadPrint::onStartTimer, Qt::QueuedConnection );
    connect( m_timer, &QTimer::timeout, this, &ThreadPrint::onTimerTimeout, Qt::QueuedConnection );
    connect( this, &ThreadPrint::insideSigKillThread, this, &ThreadPrint::onKillThread, Qt::QueuedConnection );
}

QThread *ThreadPrint::printThread() const
{
    return m_printThread;
}
