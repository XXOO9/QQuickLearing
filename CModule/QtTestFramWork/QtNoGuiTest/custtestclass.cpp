#include "CustTestClass.h"


CustTestClass::CustTestClass(QObject *parent) : QObject(parent)
{
    connect( this, &CustTestClass::sigTest, this, &CustTestClass::onSig );
}

void CustTestClass::testFunc()
{
    int a = 0;
    for( int i = 0; i < 50000; i++ ){
        a++;
    }
}

void CustTestClass::display()
{
    qDebug() << "this is display...";
    //判断是否相等
    QCOMPARE( 2, 2 );

    QTimer *timer = new QTimer();
    timer->setSingleShot( true );
    connect( timer, &QTimer::timeout, [=](){
        qDebug() << "time out...";
        QCOMPARE( 2, 2 );
        emit sigTest();
    });

    timer->start( 5000 );
    qDebug() << "state = " << timer->isActive();



}

void CustTestClass::onSig(/*bool ok*/)
{
    //    if( !ok ){
    //        qDebug() << "not ok...";
    //    }else{
    //        qDebug() << "ok !";
    //    }

    QBENCHMARK{}
    static int num = 0;
    ++num;

    qDebug() << "ok!, num = " << num;
}

