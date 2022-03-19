#include "CFunction.h"

CFunction::CFunction(QObject *parent) : QObject(parent)
{

}

CFunction::~CFunction()
{

}

void CFunction::init()
{

}

void CFunction::display(QVariant data)
{
    QMap<QString,QString> tmp = data.value<QMap<QString,QString>>();
    static int i = 0;
    while ( true ) {
        m_mutex.lock();
        if( !m_isRunning || i > 10 ){
            m_mutex.unlock();
            break;
        }
        m_mutex.unlock();
        i++;
        qDebug() << "this is CFunction:: " << QThread::currentThreadId();
        qDebug() << "test ret = " << data;
//        qDebug() << "ret1 = " << tmp.value( "1" );
//        qDebug() << "ret1 = " << tmp.value( "2" );
//        qDebug() << "ret1 = " << tmp.value( "3" );
        QThread::msleep( 500 );
    }
    emit sigFuncDone();
    qDebug() << "end of display...";

}

void CFunction::stopDisplay()
{
    m_mutex.lock();
    m_isRunning = false;
    m_mutex.unlock();
}

void CFunction::testFunc()
{
    qDebug() << "start testFunc, ThreadID = " << QThread::currentThreadId();
}
