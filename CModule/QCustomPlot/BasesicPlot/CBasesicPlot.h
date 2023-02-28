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

    virtual void paint() override;

signals:

public slots:
};

#endif // CBASESICPLOT_H
