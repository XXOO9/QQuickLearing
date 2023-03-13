#ifndef CBASESICPLOT_H
#define CBASESICPLOT_H

#ifndef QCUSTOMPLOT_USE_OPENGL
#define QCUSTOMPLOT_USE_OPENGL
#endif

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QQuickPaintedItem>
#include "../qcustomplot.h"




class CBasesicPlot : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit CBasesicPlot(QQuickPaintedItem *parent = nullptr);

    virtual void paint( QPainter *painter ) override;

    void updateCustomPlotSize();

public slots:
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
