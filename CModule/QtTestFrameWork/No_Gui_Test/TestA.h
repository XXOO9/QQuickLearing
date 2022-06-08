#ifndef TESTA_H
#define TESTA_H

#include <QObject>
#include <QTest>
#include <QString>
#include <QRandomGenerator>
#include <QDateTime>
#include <QSignalSpy>
#include "Car.h"

/*
 * https://community.kde.org/Guidelines_and_HOWTOs/UnitTests
*/


/*
 *   主要演示宏的用法
 *   主要用到的宏:
 *   QVERIFY
 *   QCOMPARE
*/


Q_DECLARE_METATYPE( Car )

class TestA : public QObject
{
    Q_OBJECT
public:
    explicit TestA(QObject *parent = nullptr);

    QVector<Car> productCar();

signals:

private:


private slots:
    void case_QVerify();

    void case_QCompare();



    /**************数据驱动测试*****************************/
    void case_many_many_content();

    void case_many_many_content_data();



private slots:
    void case_test_car_wheels();
    void case_test_car_wheels_data();
};

#endif // TESTA_H
