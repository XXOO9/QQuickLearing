#include "CTestDate.h"

CTestDate::CTestDate()
{
    testQueryDays();
}

void CTestDate::testQueryDays()
{
    QDate curDate = QDate::fromString( "20221101", "yyyyMMdd" );
    qDebug() << curDate.day();
    qDebug() << curDate.dayOfWeek();
    qDebug() << curDate.dayOfYear();
    qDebug() << curDate.daysInMonth();
    qDebug() << curDate.daysInYear();
}
