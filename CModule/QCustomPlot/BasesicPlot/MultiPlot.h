#ifndef MULTIPLOT_H
#define MULTIPLOT_H

#include <QObject>
#include <QDebug>
#include <QQuickPaintedItem>
#include "../qcustomplot.h"
#include "CMoveGrapRangeThread.h"

//#define USE_THREAD_MOVE_RANGE_FLAG true

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

    void onMouseWheel( QWheelEvent *event );

private:
    void init();

    void routeMouseEvents( QMouseEvent  *event );
    virtual void mousePressEvent( QMouseEvent *event ) override;
    virtual void mouseReleaseEvent( QMouseEvent *event ) override;
    virtual void mouseMoveEvent( QMouseEvent *event ) override;
    virtual void wheelEvent( QWheelEvent *event ) override;

private:
    QCustomPlot *m_pPlot = nullptr;
    QTimer       m_timer;
    CMoveGrapRangeThread    m_moveRangeThread;

    QPointF       m_lastPressPos;
    QCPAxisRect  *m_curAxisRect = nullptr;
};

#endif // MULTIPLOT_H
