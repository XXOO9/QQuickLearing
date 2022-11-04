#include "CInterAction.h"

CInterAction::CInterAction(QObject *parent) : QObject(parent)
{

}

QVariantMap CInterAction::queryTargetDateMonthInfo(int year, int month)
{
    return m_dateMgr.queryResult( year, month );
}

CusDateModel *CInterAction::dateMdoel()
{
    return &m_dateMdoel;
}
