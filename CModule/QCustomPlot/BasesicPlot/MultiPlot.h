#ifndef MULTIPLOT_H
#define MULTIPLOT_H

#include <QObject>
#include <QDebug>
#include <QQuickPaintedItem>
#include "../qcustomplot.h"

class MultiPlot : public QQuickPaintedItem
{
public:
    MultiPlot();

    virtual void paint( QPainter *painter ) override;

public slots:
    void updateCustomPlotSize();

    void onCustomReplot();

private:
    void init();

private:
    QCustomPlot *m_pPlot = nullptr;
    QTimer       m_timer;
};

#endif // MULTIPLOT_H
