#include "CDevCamera.h"

CDevCamera::CDevCamera(QObject *parent) : QThread(parent),
    m_pCamera( nullptr )
{
    qDebug() << "main thread id = " << QThread::currentThreadId();
    m_pCamera = new VideoCapture();
}

CDevCamera::~CDevCamera()
{
    stopThread();
    this->wait();
}

void CDevCamera::init()
{

}

void CDevCamera::run()
{
    qDebug() << "camera thread is" << QThread::currentThreadId();
    m_isCameraRunning = true;
    if( !m_pCamera->isOpened() ){
        if( !m_pCamera->open( 0 ) ){
            delete m_pCamera;
            m_pCamera = nullptr;
            return;
        }
    }
    while( true ){
        m_mutex.lock();
        if( !m_isCameraRunning ){
            m_mutex.unlock();
            break;
        }

//        qDebug() << "while thread id = " << QThread::currentThreadId();
        *m_pCamera >> m_mat;
        QImage img = matToQimage( m_mat );
        emit sigNewQimageAvailable( img );
        QThread::msleep( 20 );
        m_mutex.unlock();
    }
    m_pCamera->release();
    m_isCameraRunning = false;
//    qDebug() << "quit thread::" << QThread::currentThreadId();
}

void CDevCamera::stopThread()
{
    m_mutex.lock();
    m_isCameraRunning = false;
    m_mutex.unlock();
}

QImage CDevCamera::matToQimage(Mat frame)
{
    QImage img;

    if (frame.channels()==3)
    {
        cvtColor(frame, frame, CV_BGR2RGB);
        img = QImage( static_cast<const unsigned char *>(frame.data), frame.cols, frame.rows,
                frame.cols*frame.channels(), QImage::Format_RGB888);
    }
    else if (frame.channels()==1)
    {
        img = QImage(static_cast<const unsigned char *>(frame.data), frame.cols, frame.rows,
                frame.cols*frame.channels(), QImage::Format_ARGB32);
    }
    else
    {
        img = QImage(static_cast<const unsigned char *>(frame.data), frame.cols, frame.rows,
                frame.cols*frame.channels(), QImage::Format_RGB888);
    }

    return img;
}

