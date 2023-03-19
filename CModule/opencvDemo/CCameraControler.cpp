#include "CCameraControler.h"

CCameraControler::CCameraControler(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<cv::Mat>( "Mat" );
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

void CCameraControler::cvMat2QImage(const Mat &srcMat, QImage &targetImage)
{
//    cv::imshow( "123",srcMat );
//    waitKey( 1 );
    if (srcMat.channels()==3)
    {
        cvtColor(srcMat, srcMat, CV_BGR2RGB);
        targetImage = QImage(reinterpret_cast<const unsigned char *>(srcMat.data), srcMat.cols, srcMat.rows,
                srcMat.cols*srcMat.channels(), QImage::Format_RGB888);
    }
    else if (srcMat.channels()==1)
    {
        targetImage = QImage(reinterpret_cast<const unsigned char *>(srcMat.data), srcMat.cols, srcMat.rows,
                srcMat.cols*srcMat.channels(), QImage::Format_ARGB32);
    }
    else
    {
        targetImage = QImage(reinterpret_cast<const unsigned char *>(srcMat.data), srcMat.cols, srcMat.rows,
                srcMat.cols*srcMat.channels(), QImage::Format_RGB888);
    }
}

void CCameraControler::openCamera()
{
    qDebug() << "open camera thread = " << QThread::currentThreadId();
    if( !m_camera.isOpened() ){
        m_camera.open( 0 );
    }

    QElapsedTimer cntTimer;
    while( true ){
        cntTimer.restart();
        m_camera >> m_frame;
        cvMat2QImage( m_frame, m_img );
        emit sigNewFrameAvailable( m_img );
        qDebug() << "cost " << cntTimer.elapsed();
        qDebug() << "fps = "    << m_camera.get( CAP_PROP_FPS );
//        QThread::msleep( 5 );
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
    connect( this, &CCameraControler::insideSigOpenCamera, this, &CCameraControler::openCamera, Qt::QueuedConnection );
}
