#ifndef CBASESICPLOT_H
#define CBASESICPLOT_H

#ifndef QCUSTOMPLOT_USE_OPENGL
#define QCUSTOMPLOT_USE_OPENGL
#endif

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QQuickPaintedItem>
#include <QMouseEvent>
#include <QDebug>
#include "../qcustomplot.h"


class CBasesicPlot : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit CBasesicPlot(QQuickPaintedItem *parent = nullptr);

    virtual void paint( QPainter *painter ) override;

    Q_INVOKABLE void getName();

    Q_INVOKABLE void appendData();

    Q_INVOKABLE void startTimer();

private:
    void routeMouseEvents( QMouseEvent  *event );
    virtual void mousePressEvent( QMouseEvent *event ) override;
    virtual void wheelEvent( QWheelEvent *event ) override;

protected slots:
    void graphClicked( QCPAbstractPlottable *plottable );


public slots:
    void updateCustomPlotSize();

    void onCustomReplot();

    void onTimerTimeout();

private:
    void init();

    void initTest();

    void initPlot();

private:
    QCustomPlot *m_pPlot = nullptr;
    QTimer       m_timer;
};

#endif // CBASESICPLOT_H
