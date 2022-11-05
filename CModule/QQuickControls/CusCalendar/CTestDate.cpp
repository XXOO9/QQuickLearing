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

QVariantMap CTestDate::queryResult(int year, int month) const
{
    QVariantMap retMap;

    QDate targetDate;
    targetDate.setDate( year, month, 1 );

    retMap =
    {
        { Keys::daysInMonth, targetDate.daysInMonth() },
        { Keys::startWeekDay, targetDate.dayOfWeek() }
    };

    return retMap;
}
