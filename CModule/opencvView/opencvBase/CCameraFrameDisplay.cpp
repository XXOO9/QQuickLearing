#include "CCameraFrameDisplay.h"

#include <QPainter>

CCameraFrameDisplay::CCameraFrameDisplay()
{
    qDebug() << "1";
    init();

    open();
}

CCameraFrameDisplay::~CCameraFrameDisplay()
{

}

void CCameraFrameDisplay::paint(QPainter *painter)
{
    if( nullptr == painter ){
        return;
    }

    painter->drawImage( QPoint( 0, 0 ), m_img );
}

void CCameraFrameDisplay::open()
{
    emit m_cameraControler.sigOpenCamera();
}

void CCameraFrameDisplay::onNewImageAvailable(const QImage &srcImg)
{
    m_img = srcImg;
    update();
}

void CCameraFrameDisplay::onResized()
{
    update();
}

void CCameraFrameDisplay::init()
{
    connect( &m_cameraControler, &CCameraThreadControler::sigNewImageAvailable, this, &CCameraFrameDisplay::onNewImageAvailable );
    connect( this, &CCameraFrameDisplay::widthChanged, this, &CCameraFrameDisplay::onResized );
    connect( this, &CCameraFrameDisplay::heightChanged, this, &CCameraFrameDisplay::onResized );
}
