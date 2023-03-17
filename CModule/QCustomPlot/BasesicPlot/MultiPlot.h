#ifndef MULTIPLOT_H
#define MULTIPLOT_H

#include <QObject>
#include <QDebug>
#include <QQuickPaintedItem>
#include "../qcustomplot.h"

class MultiPlot : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MultiPlot( QQuickPaintedItem *parent = nullptr );

    virtual void paint( QPainter *painter ) override;

public slots:

    void onCustomReplot();

    void onUpdateCustomPlotSize();

private:
    void init();

private:
    QCustomPlot *m_pPlot = nullptr;
    QTimer       m_timer;
};

#endif // MULTIPLOT_H
