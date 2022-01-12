#ifndef QTCLASSTEST_H
#define QTCLASSTEST_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>

#include "../../CHttpModule/CHttpGetVideoUrls/CHttpGetVideoUrls.h"
#include "../../CHttpModule/CHttpAbstractNetWork/CHttpAbstractNetWork.h"

#include "../../CTestShardLibrary/CTestShardLibrary.h"
#include "../../CTestShardLibrary/CTestShardLibrary2.h"

class QtClassTest : public QObject
{
    Q_OBJECT
public:
    explicit QtClassTest(QObject *parent = nullptr);

    QString display();

    void initTimer();

    void startTimer();
    bool isFinished();
    void emitSig();

    void getUrls();
    void testLibrary();


signals:
    void sigTriggered();


public slots:


private:
    bool    m_isFinished{ false };
    QTimer  m_Timer;
};

#endif // QTCLASSTEST_H
