#include "TestB.h"

TestB::TestB(QObject *parent) : QObject(parent)
{

}

void TestB::init()
{
    qDebug() << "this is init funciton...";
}

void TestB::cleanup()
{
    qDebug() << "this is function clean...";
}

void TestB::case_testSignal()
{
    SignalTest *pCaseSig = new SignalTest();
    QSignalSpy sigListener( pCaseSig, &SignalTest::sigSendMultiArgs );

    //测试信号是否有效
    QVERIFY( sigListener.isValid() );

    QCOMPARE( sigListener.count(), 0 );

    emit pCaseSig->sigSendMultiArgs( "hello", "WDNMD" );
    emit pCaseSig->sigSendMultiArgs( "1234", "5678" );
//    QCOMPARE( sigListener.count(), 1 );



    qDebug() << "size = " << sigListener.size();
    qDebug() << "sig name = " << QString::fromLocal8Bit( sigListener.signal() );

    QVariantList firstSigArgs = sigListener.takeFirst();

    qDebug() << "ret = " << firstSigArgs;
}

void TestB::case_test2()
{
    QVERIFY( true );
}
