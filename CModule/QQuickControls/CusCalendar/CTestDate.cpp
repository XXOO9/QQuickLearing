#include "CTestDate.h"

#include <QRandomGenerator>

CTestDate::CTestDate()
{
//    testQueryDays();
//    testInsertTestData();
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

    int totalDays = targetDate.daysInMonth();

    QString startDay = QString::number( year ) + QString::number( month ).rightJustified( 2, '0' ) + "01";
    QString endDay = QString::number( year ) + QString::number( month ).rightJustified( 2, '0' ) + QString::number( totalDays );

    QVariantList eachDayDetailInfo = m_databaseMgr.queryRangeDateInfo( startDay, endDay );

    checkDailyInfo( eachDayDetailInfo, targetDate.dayOfWeek(), totalDays );

    retMap =
    {
        { Keys::daysInMonth,  totalDays },
        { Keys::startWeekDay, targetDate.dayOfWeek() },
        { Keys::eachDayDetaileInfo, eachDayDetailInfo },
    };

    return retMap;
}

void CTestDate::checkDailyInfo(QVariantList &srcList, int weekDayOffset, int monthDays ) const
{
    QVariantList tmpTotalList = generateCountEmptyDateInfo( weekDayOffset, monthDays );
    QVariantMap tmpDayInfoMap;

    while( srcList.size() > 0 ){
//        qDebug() << "size = " << srcList.size();
        tmpDayInfoMap = srcList.takeFirst().toMap();
        tmpTotalList.replace( tmpDayInfoMap.value( "dateIndex" ).toInt() + weekDayOffset - 2, tmpDayInfoMap );
    }

    srcList = tmpTotalList;
}

QVariantList CTestDate::generateCountEmptyDateInfo( int weekdayOffset, int monthDays ) const
{
    QVariantMap tmpRetMap;
    QVariantList retList;

    tmpRetMap = {
        { "dateIndex", 0 },
        { "hours", 0 },
        { "timeCnt", 0 },
        { "cost", 0 }
    };

    while( --weekdayOffset ){
        retList << tmpRetMap;
    }

    for( int dayIndex = 1; dayIndex <= monthDays; dayIndex++ ){
        tmpRetMap[ "dateIndex" ] = dayIndex;
        retList << tmpRetMap;
    }

    tmpRetMap[ "dateIndex" ] = 0;
    while( retList.size() < 42 ){
        retList << tmpRetMap;
    }

    return retList;
}

void CTestDate::testInsertTestData()
{
    QDate startDay = QDate::fromString( "20221101", "yyyyMMdd" );
    QDate endDay = QDate::fromString( "20221130", "yyyyMMdd" );
    QDate tmpDay = startDay;

    QRandomGenerator tmpRandom;
    while( tmpDay <= endDay ){
        qDebug() << tmpDay.toString( "yyyyMMdd" );
        int hour = tmpRandom.bounded(0, 10);
        int timeCnt = tmpRandom.bounded( 0, 5 );
        double cost = tmpRandom.bounded( 0, 8 );
        m_databaseMgr.insertNewDateInfo( tmpDay.toString( "yyyyMMdd" ), hour, timeCnt, cost );
        tmpDay = tmpDay.addDays( 1 );
    }
}

const CDatabaseMgr &CTestDate::databaseMgr() const
{
    return m_databaseMgr;
}
