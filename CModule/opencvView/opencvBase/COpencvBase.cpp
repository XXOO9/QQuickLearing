#include "COpencvBase.h"

#include <QImage>

COpencvBase::COpencvBase(QObject *parent) : QObject(parent)
{
    showCameraInfos();
    qDebug() << "camera create ID = " << QThread::currentThreadId();
    init();
}

COpencvBase::~COpencvBase()
{
    if( nullptr != m_pCameraThread ){
        if( m_pCameraThread->isRunning() ){
            onCloseCamera();
            m_pCameraThread->quit();
            m_pCameraThread->wait();
            qDebug() << "done";
        }
    }
}

void COpencvBase::onOpenCamera()
{
    qDebug() << "camera Thread ID = " << QThread::currentThreadId();
    VideoCapture cap( 0 );

    //这里也是个坑，必须先设置压缩格式，以高分辨率打开摄像头才不卡
//    cap.set( CV_CAP_PROP_FOURCC, cv::VideoWriter::fourcc( 'M', 'J', 'P', 'G' ) );
//    cap.set( CV_CAP_PROP_FRAME_WIDTH, 1920 );
//    cap.set( CV_CAP_PROP_FRAME_HEIGHT, 1080 );

    setCameraRunningFlag( true );
    QElapsedTimer timer;
    Mat tmpMat;
    forever{
        timer.restart();
        if( !cameraRunningFlag() ){
            return;
        }

        cap >> m_mat;
        resize( m_mat, tmpMat, Size( 1920, 1080 ) );

        emit sigNewFrameAvailable( mat2Image( tmpMat ) );
    }
}

void COpencvBase::onCloseCamera()
{
    setCameraRunningFlag( false );
}

void COpencvBase::init()
{
    if( nullptr == m_pCameraThread ){
        m_pCameraThread = new QThread();
    }

    this->moveToThread( m_pCameraThread );
    initConnection();
    m_pCameraThread->start();
}

void COpencvBase::initConnection()
{
    connect( m_pCameraThread, &QThread::finished, m_pCameraThread, &QObject::deleteLater );
}

void COpencvBase::showCameraInfos()
{
    for( int i = 0; i < 10; i++ ){
        VideoCapture cap( i );
        if( cap.isOpened() ){
            qDebug() << "name = " << cap.get( CAP_PROP_POS_MSEC  );
            qDebug() << "Camera " << i << ": " << cap.get(  CV_CAP_PROP_FRAME_WIDTH ) << "x" << cap.get( CV_CAP_PROP_FRAME_HEIGHT );
            qDebug() << "FPS = " << cap.get( CAP_PROP_FPS );
            cap.release();
        }
    }
}

bool COpencvBase::cameraRunningFlag()
{
    m_mutex.lock();
    bool ok = m_cameraRunningFlag;
    m_mutex.unlock();
    return ok;
}

void COpencvBase::setCameraRunningFlag(bool cameraRunningFlag)
{
    m_mutex.lock();
    m_cameraRunningFlag = cameraRunningFlag;
    m_mutex.unlock();
}

QImage COpencvBase::mat2Image(const Mat &srcMat)
{
    QImage targetImage;

    //这是个大坑，opencv默认的颜色通道排列是BGR, 需要转换一下才能成RGB
    cvtColor(srcMat, srcMat, CV_BGR2RGB);
    targetImage = QImage( srcMat.data, srcMat.cols, srcMat.rows, QImage::Format_RGB888 );
//    if (srcMat.channels()==3)
//    {
//        cvtColor(srcMat, srcMat, CV_BGR2RGB);
//        targetImage = QImage(reinterpret_cast<const unsigned char *>(srcMat.data), srcMat.cols, srcMat.rows,
//                srcMat.cols*srcMat.channels(), QImage::Format_RGB888);
//    }
//    else if (srcMat.channels()==1)
//    {
//        targetImage = QImage(reinterpret_cast<const unsigned char *>(srcMat.data), srcMat.cols, srcMat.rows,
//                srcMat.cols*srcMat.channels(), QImage::Format_ARGB32);
//    }
//    else
//    {
//        targetImage = QImage(reinterpret_cast<const unsigned char *>(srcMat.data), srcMat.cols, srcMat.rows,
//                srcMat.cols*srcMat.channels(), QImage::Format_RGB888);
//    }

    return targetImage;
}
