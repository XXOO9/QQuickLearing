#ifndef CMOVEGRAPRANGETHREAD_H
#define CMOVEGRAPRANGETHREAD_H

#include <QThread>
#include <QDebug>
#include <QObject>
#include "./thirdParty/qcustomplot/qcustomplot.h"

class CMoveGrapRangeThread : public QThread
{
public:
    CMoveGrapRangeThread();

    virtual void run() override;

QCustomPlot *m_pPlot = nullptr;


};

#endif // CMOVEGRAPRANGETHREAD_H
