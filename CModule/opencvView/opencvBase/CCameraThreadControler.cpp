#include "CCameraThreadControler.h"

CCameraThreadControler::CCameraThreadControler(QObject *parent) : QObject(parent)
{
    init();
}

void CCameraThreadControler::init()
{
    connect( &m_camera, &COpencvBase::sigNewFrameAvailable, this, &CCameraThreadControler::sigNewImageAvailable );
    connect( this, &CCameraThreadControler::sigOpenCamera, &m_camera, &COpencvBase::onOpenCamera );
    connect( this, &CCameraThreadControler::sigCloseCamera, &m_camera, &COpencvBase::onCloseCamera );
}
