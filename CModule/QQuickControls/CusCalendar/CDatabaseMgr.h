#ifndef CDATABASEMGR_H
#define CDATABASEMGR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QDebug>

namespace Keys {
    const QString databaseName = "CKX";
    const QString dayIndex = "dateIndex";
    const QString hours = "hours";
    const QString timeCnt = "timeCnt";
}

class CDatabaseMgr
{
public:
    enum DataField{
        DateTime = 0,
        Hours,
        TimeCnt,
    };

    CDatabaseMgr();
    ~CDatabaseMgr();

    bool insertNewDateInfo(const QString &date, const double &hour, const double &timeCnt ) const;

    bool insertNewDateInfo(const int &date, const double &hour, const double &timeCnt ) const;

    QVariantList queryRangeDateInfo(const QString &startDayDate, const QString &endDayDate ) const;

    bool changeTargetDateInfo( const int &targetDate, const int &hour, const int &timeCnt ) const;

private:
    void initDatabase();

    void initTables();

    void resetSqlExecute();

    void checkTablesExisted();

    bool isTargetTableExisted(const QString &tableName);

    bool isTargetDateRecordExisted( const int &targetDate ) const;

    int getDayIndex( const int &date ) const;
private:
    QSqlDatabase    m_database;
    QSqlQuery      *m_pSqlExecute = nullptr;
};

#endif // CDATABASEMGR_H
