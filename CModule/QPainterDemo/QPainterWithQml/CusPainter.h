#ifndef CUSPAINTER_H
#define CUSPAINTER_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QDebug>

class CusPainter : public QQuickPaintedItem
{
    Q_OBJECT
public:
    CusPainter();

    virtual ~CusPainter() override;

    virtual void paint( QPainter *painter ) override;

signals:
    Q_INVOKABLE void sigText();
};

#endif // CUSPAINTER_H
