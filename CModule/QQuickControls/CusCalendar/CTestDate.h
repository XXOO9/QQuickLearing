#ifndef CTESTDATE_H
#define CTESTDATE_H

#include <QDate>
#include <QDebug>

const int commonYearDays = 365;
const int leapYearDays = 366;

namespace Keys {
    const QString daysInMonth  = "daysInMonth";
    const QString startWeekDay = "startWeekDay";
}

class CTestDate
{
public:
    CTestDate();

    void testQueryDays();

    QVariantMap queryResult( int year, int month ) const;
};

#endif // CTESTDATE_H
