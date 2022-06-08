#include "TestA.h"

TestA::TestA(QObject *parent) : QObject(parent)
{

}

QVector<Car> TestA::productCar()
{
    QVector<Car> vecCars;

    //利用时间产生随机数种子
    quint32 seed = quint32(QDateTime::currentDateTime().toSecsSinceEpoch() );
    QRandomGenerator randomer( seed );
    for( int i = 0; i < 20; i++ ){
        Car tmpCar( "TSL", randomer.bounded( 1, 5 ), "color" );
        vecCars<< tmpCar;
    }

    return vecCars;
}

void TestA::case_QVerify()
{
    QVERIFY( 1 + 1 == 2 );

    //条件不成立时，打印信息
    //    QVERIFY2( true, "WDNMD" );

    //这是啥?
    //    QTRY_VERIFY()
}

void TestA::case_QCompare()
{
    QString actual = "HeLlo";
    QString expected = "HELLO";
    QCOMPARE( actual.toUpper(), expected );

    //    QWARN("this is waring");
    //    QCOMPARE( actual, expected );
}

void TestA::case_many_many_content()
{
    //    QString expected = "HELLO";
    //    QCOMPARE( QString("hEllO").toUpper(), expected );
    //    QCOMPARE( QString("HELLo").toUpper(), expected );
    //    QCOMPARE( QString("HEllo").toUpper(), expected );
    //    QCOMPARE( QString("heLLo").toUpper(), expected );
    //    QCOMPARE( QString("hELlo").toUpper(), expected );
    //    QCOMPARE( QString("hello").toUpper(), expected );



    /*******************************************************/


    QFETCH( QString, src );
    QFETCH( QString, target );


    QCOMPARE( src.toUpper(), target );
}

void TestA::case_many_many_content_data()
{
    QTest::addColumn<QString>( "src" );
    QTest::addColumn<QString>( "target" );

    QTest::newRow( "firstRow" ) << "hello" << "HELLO";
    QTest::newRow( "secondRow" ) << "HELLO" << "HELLO";
}

void TestA::case_test_car_wheels()
{
    QFETCH( Car, src );
    QFETCH( int, standardWheels );

    QCOMPARE( src.wheels(), standardWheels );
}

void TestA::case_test_car_wheels_data()
{
    QTest::addColumn<Car>( "src" );
    QTest::addColumn<int>( "standardWheels" );

    QVector<Car> vecCars = productCar();
    int standardWheels = 4;
    for( int i = 0; i < vecCars.size(); i++ ){
        QTest::newRow( QString::number( i ).toLocal8Bit().data() ) << vecCars[i] << standardWheels;
    }

}
