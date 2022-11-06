#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include "CTestDate.h"
#include "./CusDateModel.h"
#include <QRandomGenerator>
#include "CLocalConfig.h"

class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    //查询当月的信息
    Q_INVOKABLE QVariantMap queryTargetDateMonthInfo( int year, int month );

    //更新指定日期的加时长信息
    Q_INVOKABLE bool setTargetDateHourInfo( int date, int hour, int timeCnt );

    Q_INVOKABLE bool isNewUser();

    Q_INVOKABLE void setUserName( QString userName );

    CusDateModel *dateMdoel();

private:
    CTestDate       m_dateMgr;
    CusDateModel    m_dateMdoel;
    CLocalConfig    m_localConfig;
};

#endif // CINTERACTION_H
