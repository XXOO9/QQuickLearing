#include "CVideoFrameProvider.h"

CVideoFrameProvider::CVideoFrameProvider(QQuickPaintedItem *parent) : QQuickPaintedItem(parent)
{
    qRegisterMetaType<cv::Mat>( "Mat" );
    init();
}

CVideoFrameProvider::~CVideoFrameProvider()
{

}

void CVideoFrameProvider::paint(QPainter *painter)
{
    painter->drawImage( QRect( 0, 0, m_img.width(), m_img.height() ), m_img  );
}

void CVideoFrameProvider::onNewFrameAvailable(const QImage &newFrame)
{
    m_img = newFrame;

    update();
}

void CVideoFrameProvider::init()
{
    connect( &m_camera, &CCameraControler::sigNewFrameAvailable, this, &CVideoFrameProvider::onNewFrameAvailable );
}
