#ifndef CVIDEOFRAMEPROVIDER_H
#define CVIDEOFRAMEPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QAbstractVideoSurface>
#include <QQuickPaintedItem>
#include <QPainter>
#include "./CCameraControler.h"
#include <QMetaType>
#include <QImage>

class CVideoFrameProvider : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit CVideoFrameProvider(QQuickPaintedItem *parent = nullptr);
    virtual ~CVideoFrameProvider() override;

    virtual void paint( QPainter *painter ) override;

public slots:
    void onNewFrameAvailable( const QImage &newFrame );

signals:
    void sigNewFrameAvailable();

private:
    void init();

private:
    CCameraControler    m_camera;
    QImage              m_img;
};

#endif // CVIDEOFRAMEPROVIDER_H
