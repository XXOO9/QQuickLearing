#ifndef CTESTDATE_H
#define CTESTDATE_H

#include <QDate>
#include <QDebug>

const int commonYearDays = 365;
const int leapYearDays = 366;

class CTestDate
{
public:
    CTestDate();

    void testQueryDays();
};

#endif // CTESTDATE_H
