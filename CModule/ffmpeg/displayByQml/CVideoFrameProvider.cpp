#include "CVideoFrameProvider.h"

CVideoFrameProvider::CVideoFrameProvider(QThread *parent) : QThread(parent)
{
    connect( &m_ffmpeg, &CFFmpegLevel1::sigNewFrameAvailable, this, &CVideoFrameProvider::onNewFrameAvailable, Qt::QueuedConnection );
}

CVideoFrameProvider::~CVideoFrameProvider()
{

}

void CVideoFrameProvider::setFormat(int width, int height, QVideoFrame::PixelFormat format)
{
    QSize size( width, height );

    QVideoSurfaceFormat tmpFormat( size, format );
    m_videoFormat = tmpFormat;

    if( nullptr != m_pVideoSurface ){
        if( m_pVideoSurface->isActive() ){
            m_pVideoSurface->stop();
        }
        m_videoFormat = m_pVideoSurface->nearestFormat( m_videoFormat );
        m_pVideoSurface->start( m_videoFormat );
    }
}

void CVideoFrameProvider::test()
{

}

void CVideoFrameProvider::run()
{
    m_ffmpeg.savePerFrameAsYUV420();
}

void CVideoFrameProvider::onNewFrameAvailable(const QVideoFrame &newFrame)
{
    if( nullptr == m_pVideoSurface ){
        return;
    }

    setFormat( newFrame.width(), newFrame.height(), newFrame.pixelFormat() );
    m_pVideoSurface->present( newFrame );
}

QAbstractVideoSurface *CVideoFrameProvider::videoSurface()
{
    return m_pVideoSurface;
}

void CVideoFrameProvider::setVideoSurface(QAbstractVideoSurface *surface)
{
    if( m_pVideoSurface != nullptr && m_pVideoSurface != surface && m_pVideoSurface->isActive() ){
        m_pVideoSurface->stop();
    }

    m_pVideoSurface = surface;

    if( m_pVideoSurface != nullptr && m_videoFormat.isValid() ){
        m_videoFormat = m_pVideoSurface->nearestFormat( m_videoFormat );
        m_pVideoSurface->start( m_videoFormat );
    }

}
