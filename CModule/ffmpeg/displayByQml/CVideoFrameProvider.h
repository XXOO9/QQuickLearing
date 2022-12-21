#ifndef CVIDEOFRAMEPROVIDER_H
#define CVIDEOFRAMEPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include "CFFmpegLevel1.h"

class CVideoFrameProvider : public QThread
{
    Q_OBJECT
    Q_PROPERTY( QAbstractVideoSurface *videoSurface READ videoSurface WRITE setVideoSurface )
public:
    explicit CVideoFrameProvider(QThread *parent = nullptr);
    virtual ~CVideoFrameProvider() override;

    QAbstractVideoSurface *videoSurface();
    void setVideoSurface( QAbstractVideoSurface *surface );

    void setFormat( int width, int height, QVideoFrame::PixelFormat format );

    Q_INVOKABLE void test();

    virtual void run() override;

signals:
    void sigNewViewFrameAvailable( const QVideoFrame &srcFrame );

public slots:
    void onNewFrameAvailable( const QVideoFrame &newFrame );




private:
    QAbstractVideoSurface   *m_pVideoSurface = nullptr;
    QVideoSurfaceFormat     m_videoFormat;

    CFFmpegLevel1           m_ffmpeg;

};

#endif // CVIDEOFRAMEPROVIDER_H
