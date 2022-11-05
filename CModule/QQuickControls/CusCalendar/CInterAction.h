#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include "CTestDate.h"
#include "./CusDateModel.h"
#include <QRandomGenerator>

class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    //查询当月的信息
    Q_INVOKABLE QVariantMap queryTargetDateMonthInfo( int year, int month );

    CusDateModel *dateMdoel();

private:
    CTestDate       m_dateMgr;
    CusDateModel    m_dateMdoel;
};

#endif // CINTERACTION_H
