#ifndef CBASESICPLOT_H
#define CBASESICPLOT_H

#include <QObject>
#include <QDebug>
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

private:
    void init();

    void initPlot();

private:
    QCustomPlot *m_pPlot = nullptr;
};

#endif // CBASESICPLOT_H
