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

CusDateModel *CInterAction::dateMdoel()
{
    return &m_dateMdoel;
}
