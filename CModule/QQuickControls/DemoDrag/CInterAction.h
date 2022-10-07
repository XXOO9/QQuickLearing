#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "CusListDataModel.h"

class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    void registEngine(QQmlApplicationEngine *pEngine );


private:
    CusListDataModel         m_listModel;
    QQmlApplicationEngine   *m_pEngine = nullptr;

};

#endif // CINTERACTION_H
