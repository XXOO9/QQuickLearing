#ifndef CPAINTERDRAWBOARD_H
#define CPAINTERDRAWBOARD_H

#include <QObject>
#include <QDebug>
#include <QQuickPaintedItem>
#include <QMouseEvent>
#include <QPainter>
#include <QQuickItemGrabResult>

class CPainterDrawBoard : public QQuickPaintedItem
{
    Q_OBJECT
public:
    CPainterDrawBoard( QQuickPaintedItem *parent = nullptr );
    virtual ~CPainterDrawBoard();

    virtual void paint( QPainter *painter ) override;

    void setFileName(const QString &fileName);
    void setSavePath(const QString &savePath);

public:
    Q_INVOKABLE void clear();
    Q_INVOKABLE void save( QObject *obj );

private:
    virtual void mousePressEvent( QMouseEvent *event ) override;
    virtual void mouseReleaseEvent( QMouseEvent *event ) override;
    virtual void mouseMoveEvent( QMouseEvent *event ) override;

private:
    QString                              m_fileName = "sign.png";
    QString                              m_savePath = "./";
    QQuickItem                          *m_pItem = nullptr;
    QSharedPointer<QQuickItemGrabResult> m_grab_result;
    QPixmap                              m_pixmap;
    QPolygonF                            m_path;
    bool                                 m_pressed = false;

};

#endif // CPAINTERDRAWBOARD_H
