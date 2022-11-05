#ifndef CTESTDATE_H
#define CTESTDATE_H

#include <QDate>
#include <QDebug>
#include "CDatabaseMgr.h"

const int commonYearDays = 365;
const int leapYearDays = 366;

namespace Keys {
    const QString daysInMonth  = "daysInMonth";
    const QString startWeekDay = "startWeekDay";
    const QString eachDayDetaileInfo = "dayDetailInfo";
}

class CTestDate
{
public:
    CTestDate();

    void testQueryDays();

    QVariantMap queryResult( int year, int month ) const;

private:
    void testInsertTestData();

private:
    CDatabaseMgr    m_databaseMgr;
};

#endif // CTESTDATE_H
