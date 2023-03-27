#ifndef CCAMERAFRAMEDISPLAY_H
#define CCAMERAFRAMEDISPLAY_H

#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QDebug>
#include <QImage>
#include "COpencvBase.h"
#include "CCameraThreadControler.h"

class CCameraFrameDisplay : public QQuickPaintedItem
{
public:
    CCameraFrameDisplay();
    virtual ~CCameraFrameDisplay() override;

    virtual void paint( QPainter *painter ) override;

    Q_INVOKABLE void open();

public slots:
    void onNewImageAvailable( const QImage &srcImg );
    void onResized();
private:
    void init();

private:
    QImage m_img;
    CCameraThreadControler  m_cameraControler;
};

#endif // CCAMERAFRAMEDISPLAY_H
