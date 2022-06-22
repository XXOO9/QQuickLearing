#ifndef CUSQQUICKPAINTERITEM_H
#define CUSQQUICKPAINTERITEM_H

#include <QQuickPaintedItem>
#include <QObject>
#include <QQuickItem>
#include <QPainter>
#include <QPen>
#include <QBrush>

class CusQQuickPainterItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ getHeight WRITE setHeight NOTIFY heightChanged)

public:
    CusQQuickPainterItem();
    virtual ~CusQQuickPainterItem();

    virtual void paint( QPainter *painter ) override;

    Q_INVOKABLE void init();

    int width() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);

signals:
    void widthChanged();
    void heightChanged();

private:
    QPainter *m_painter = nullptr;
    int       m_width = 0;
    int       height  = 0;

};

#endif // CUSQQUICKPAINTERITEM_H
