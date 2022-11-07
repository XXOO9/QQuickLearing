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

bool CInterAction::setTargetDateHourInfo( double date, double hour, double timeCnt, double cost )
{
    bool ok = m_dateMgr.databaseMgr().changeTargetDateInfo( date, hour, timeCnt, cost );
    qDebug() << "change date " << date << "'s  hour: " << hour << " timeCnt: " << timeCnt << "'s ret = " << ok;
    return ok;
}

bool CInterAction::isNewUser()
{
    QVariantMap retMap =  m_localConfig.getConfigs();
    if( retMap.value( LocalConfigKeys::userName ).toString() == "CXK" ){
        return true;
    }

    return false;
}

void CInterAction::setUserName(QString userName)
{
    m_localConfig.setTargetKeyValue( "userName", userName );
}

QString CInterAction::getUserName()
{
    return m_localConfig.getConfigs().value( "userName" ).toString();
}

CusDateModel *CInterAction::dateMdoel()
{
    return &m_dateMdoel;
}
