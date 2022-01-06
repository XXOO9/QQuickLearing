#ifndef CDEVCAMERA_H
#define CDEVCAMERA_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QImage>
#include <QDebug>
#include "opencv2/video/video.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

//应该将这个类放在子线程里面，虽然opencv捕获摄像头图像貌似不会阻塞主线程，但是还是建议放在子线程里面

using namespace cv;

class CDevCamera : public QThread
{
    Q_OBJECT
public:
    explicit CDevCamera(QObject *parent = nullptr);
    virtual ~CDevCamera() override;

    void init();

    virtual void run() override;
    void stopThread();

private:
    QImage matToQimage( Mat frame );

signals:
    void sigNewQimageAvailable( QImage img );

public slots:

private:
    VideoCapture     *m_pCamera;
    Mat               m_mat;
    QMutex            m_mutex;
    bool              m_isCameraRunning{ false };
};

#endif // CDEVCAMERA_H
