#ifndef MULTIPLOT_H
#define MULTIPLOT_H

#include <QObject>
#include <QDebug>
#include <QQuickPaintedItem>
#include "../qcustomplot.h"
#include "CMoveGrapRangeThread.h"

#define USE_THREAD_MOVE_RANGE_FLAG true

class MultiPlot : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MultiPlot( QQuickPaintedItem *parent = nullptr );

    virtual void paint( QPainter *painter ) override;

public slots:

    void onCustomReplot();

    void onUpdateCustomPlotSize();

    void onTimerTimeout();

private:
    void init();

private:
    QCustomPlot *m_pPlot = nullptr;
    QTimer       m_timer;
    CMoveGrapRangeThread    m_moveRangeThread;
};

#endif // MULTIPLOT_H
