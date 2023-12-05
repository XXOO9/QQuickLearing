#ifndef CPLOTLOADDATATHREAD_H
#define CPLOTLOADDATATHREAD_H

#include <QThread>
#include <QDebug>
#include "./thirdParty/qcustomplot/qcustomplot.h"

class CPlotLoadDataThread : public QThread
{
    Q_OBJECT
public:
    CPlotLoadDataThread();

    virtual void run() override;

signals:
    void sigLoadFinished();

public:
    QCustomPlot *m_pPlot = nullptr;
};

#endif // CPLOTLOADDATATHREAD_H
