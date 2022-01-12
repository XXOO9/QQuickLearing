#include "QtClassTest.h"

QtClassTest::QtClassTest(QObject *parent) : QObject(parent)
{
    qDebug() << "start...";
    testLibrary();
    initTimer();
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
       emitSig();
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

void QtClassTest::emitSig()
{
    emit sigTriggered();
}

void QtClassTest::getUrls()
{
//    const QString s = "523161";
    //    CHttpGetVideoUrls p( s );
}

void QtClassTest::testLibrary()
{
    CTestShardLibrary test;
    CTestShardLibrary2 *test2 = CTestShardLibrary2::getInstance();
    qDebug() << test.display();
    qDebug() << test2->display();
}
