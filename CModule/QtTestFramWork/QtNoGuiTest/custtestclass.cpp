#include "CustTestClass.h"


CustTestClass::CustTestClass(QObject *parent) : QObject(parent)
{
    connect( this, &CustTestClass::sigTestArgument, this, &CustTestClass::onSigWithArgument );
    connect( this, &CustTestClass::sigTestNoArgument, this, &CustTestClass::onSigNoArgument );
}

void CustTestClass::testFunc()
{
    int a = 0;
    for( int i = 0; i < 50000; i++ ){
        a++;
    }
}

void CustTestClass::sendSignalWithArgument()
{
    qDebug() << "this is display...";
    //判断是否相等
    QCOMPARE( 2, 2 );

    emit sigTestArgument( "argument" );

//    QTimer *timer = new QTimer();
//    timer->setSingleShot( true );
//    connect( timer, &QTimer::timeout, [=](){
//        qDebug() << "time out...";
//        QCOMPARE( 2, 2 );
//        emit sigTest( false );
//    });

//    timer->start( 5000 );
    //    qDebug() << "state = " << timer->isActive();
}

void CustTestClass::sendSignalNoArgument()
{
    qDebug() << "going to send signal with no argument...";
    emit sigTestNoArgument();
}

void CustTestClass::onSigWithArgument( QString content )
{
    qDebug() << "recv content = " << content;
}

void CustTestClass::onSigNoArgument()
{
    qDebug() << "this is onSigNoArgument";
}

void CustTestClass::someMacro()
{
    QVERIFY( true );
    QCOMPARE( 1, 1 );
}

void CustTestClass::testQString()
{
    QFETCH( QString, string );
    QFETCH( QString, result );

    qDebug() << "string = " << string;
    qDebug() << "result = " << result;
}

void CustTestClass::testQString_data()
{
    QTest::addColumn<QString>( "string" );
    QTest::addColumn<QString>( "result" );

    QTest::newRow( "first" ) << "hello" << "HELLO";
    QTest::newRow( "second" ) << "Hello" << "HELLO";
    QTest::newRow( "third" ) << "HELLO" << "HELLO";
}

