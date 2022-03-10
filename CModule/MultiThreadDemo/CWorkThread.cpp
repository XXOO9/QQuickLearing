#include "CWorkThread.h"

CWorkThread::CWorkThread(QObject *parent) : QObject(parent), m_pWorkThread( nullptr )
{
    init();

//    startDisplay();
}

CWorkThread::~CWorkThread()
{
    if( m_pWorkThread->isRunning() ){
        qDebug() << "shut down while thread is still running...";
        m_func.stopDisplay();
        m_pWorkThread->quit();
        bool ok = m_pWorkThread->wait();
        qDebug() << "ret = " << ok;
    }else{
        qDebug() << "shut down while thread is not running...";
    }
}

void CWorkThread::init()
{
    //new 出一个用于工作的线程
    m_pWorkThread = new QThread();

    //将目标对象放入工作线程
    m_func.moveToThread( m_pWorkThread );

    //链接信号槽
    initConnection();

    //开启线程, 此刻只是开启线程, 实际耗时函数需要通过信号触发
    m_pWorkThread->start();
}

void CWorkThread::initConnection()
{
    connect( this, &CWorkThread::sigStartDisplay, &m_func, &CFunction::display );
    connect( &m_func, &CFunction::sigFuncDone, m_pWorkThread, &QThread::quit );
    connect( m_pWorkThread, &QThread::finished, this, &QObject::deleteLater );
    connect( m_pWorkThread, &QThread::finished, m_pWorkThread, &QObject::deleteLater );
}

void CWorkThread::startDisplay()
{
    qDebug() << "start display, ThreadID = " << QThread::currentThreadId();
    emit sigStartDisplay();
}

void CWorkThread::stopDisplay()
{
   m_func.stopDisplay();
}
