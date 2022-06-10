#ifndef THREADMGR_H
#define THREADMGR_H

#include <QObject>
#include <QDebug>

#include "ThreadPrint.h"

class ThreadMgr : public QObject
{
    Q_OBJECT
public:
    explicit ThreadMgr(QObject *parent = nullptr);
    virtual ~ThreadMgr() override;

    Q_INVOKABLE void startPrint();

    Q_INVOKABLE void stopThread();

    Q_INVOKABLE void killThread();

    Q_INVOKABLE void timerControler( bool ok );

    Q_INVOKABLE void deletePrinter();

private:
    ThreadPrint *m_pPrintThread = nullptr;

};

#endif // THREADMGR_H
