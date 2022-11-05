#include "CInterAction.h"

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{
//    testInsertTestData();
}

QVariantMap CInterAction::queryTargetDateMonthInfo(int year, int month)
{
    QVariantMap retMap = m_dateMgr.queryResult( year, month );
    return retMap;
}

bool CInterAction::setTargetDateHourInfo(int date, int hour, int timeCnt)
{
    bool ok = m_dateMgr.databaseMgr().changeTargetDateInfo( date, hour, timeCnt );
    qDebug() << "change date " << date << "'s  hour: " << hour << " timeCnt: " << timeCnt << "'s ret = " << ok;
    return ok;
}

CusDateModel *CInterAction::dateMdoel()
{
    return &m_dateMdoel;
}
