#include "QtClassTest.h"

QtClassTest::QtClassTest(QObject *parent) : QObject(parent)
{
    initTimer();
}

QtClassTest::~QtClassTest()
{

}

QString QtClassTest::display()
{
    return "WDNMD_Qt";
}

void QtClassTest::initTimer()
{
    m_Timer.setInterval( 3000 );
    connect( &m_Timer, &QTimer::timeout, [=](){
       qDebug() << "Time out...";
       m_isFinished = true;
    });
}

void QtClassTest::startTimer()
{
    m_Timer.start();
}

bool QtClassTest::isFinished()
{
    return m_isFinished;
}
