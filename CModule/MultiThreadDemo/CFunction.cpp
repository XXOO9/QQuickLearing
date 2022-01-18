#include "CFunction.h"

CFunction::CFunction(QObject *parent) : QObject(parent)
{

}

CFunction::~CFunction()
{

}

void CFunction::display()
{
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
        QThread::msleep( 500 );
    }
    qDebug() << "end of display...";

}

void CFunction::stopDisplay()
{
    m_mutex.lock();
    m_isRunning = false;
    m_mutex.unlock();
}
