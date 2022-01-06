#include "CDevCameraControl.h"

CDevCameraControl::CDevCameraControl(QObject *parent) : QObject(parent)
  ,m_pDevCamera( nullptr )
  ,m_pImgProvider( nullptr )
{
    init();

}

CDevCameraControl::~CDevCameraControl()
{

}

void CDevCameraControl::init()
{
    m_pDevCamera = new CDevCamera( this );
    m_pImgProvider = new CImageProvider();
    initConnection();
}

void CDevCameraControl::initConnection()
{
    connect( m_pDevCamera, &CDevCamera::sigNewQimageAvailable, this, &CDevCameraControl::onNewImageAvaliable );
}

void CDevCameraControl::openCamera()
{
    m_pDevCamera->start();
}

void CDevCameraControl::closeCamera()
{
    m_pDevCamera->stopThread();
}

void CDevCameraControl::onNewImageAvaliable(QImage img)
{
    m_pImgProvider->setImage( img );
    emit sigImgProviderReadyFresh();
}

CImageProvider *CDevCameraControl::imgProvider() const
{
    return m_pImgProvider;
}

void CDevCameraControl::setPImgProvider(CImageProvider *pImgProvider)
{
    m_pImgProvider = pImgProvider;
}
