#include "CCameraControler.h"

CCameraControler::CCameraControler(QObject *parent) : QObject(parent)
{
    qDebug() << "construct thread = " << QThread::currentThreadId();
    init();

    emit insideSigOpenCamera();
}

CCameraControler::~CCameraControler()
{
    if( nullptr != m_pCameraThread ){
        if( m_pCameraThread->isRunning() ){
            m_pCameraThread->quit();
            bool ok = m_pCameraThread->wait();
        }
    }
}

void CCameraControler::openCamera()
{
    qDebug() << "open camera thread = " << QThread::currentThreadId();
    if( !m_camera.isOpened() ){
        m_camera.open( 0 );
    }

    while( true ){
        m_camera >> m_frame;
        QThread::msleep( 20 );
    }
}

void CCameraControler::init()
{
    initThread();
    initInsideConnection();
}

void CCameraControler::initThread()
{
    if( nullptr == m_pCameraThread ){
        m_pCameraThread = new QThread();
    }

    this->moveToThread( m_pCameraThread );
    m_pCameraThread->start();
}

void CCameraControler::initInsideConnection()
{
    connect( this, &CCameraControler::insideSigOpenCamera, this, &CCameraControler::openCamera );
}
