#ifndef CUSQQUICKPAINTERITEM_H
#define CUSQQUICKPAINTERITEM_H

#include <QQuickPaintedItem>
#include <QObject>
#include <QQuickItem>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include "qcustomplot.h"

class CusQQuickPainterItem : public QQuickPaintedItem{

    Q_OBJECT
public:
    CusQQuickPainterItem( QQuickPaintedItem *parent = nullptr );


    Q_INVOKABLE void init();

protected:
    virtual void paint( QPainter *painter) override;

private slots:
    void updateCustomPlotSize();
    void onCustomPlotReplot();


private:
    QCustomPlot *m_pCustomplot = nullptr;


};

#endif // CUSQQUICKPAINTERITEM_H
