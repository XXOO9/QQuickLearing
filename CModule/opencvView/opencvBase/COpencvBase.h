#ifndef COPENCVBASE_H
#define COPENCVBASE_H

#include <QElapsedTimer>
#include <QObject>
#include <QMutex>
#include <QDebug>
#include <QThread>
#include <QMutex>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/video.hpp"

using namespace cv;
class COpencvBase : public QObject
{
    Q_OBJECT
public:
    explicit COpencvBase(QObject *parent = nullptr);
    virtual ~COpencvBase() override;

    bool cameraRunningFlag();
    void setCameraRunningFlag(bool cameraRunningFlag);

    static QImage mat2Image( const Mat &srcMat );

signals:
    void sigNewFrameAvailable( const QImage &srcImg );

public slots:
    void onOpenCamera();
    void onCloseCamera();

private:
    void init();
    void initConnection();
    void showCameraInfos();

private:
    bool     m_cameraRunningFlag = false;
    QMutex   m_mutex;
    QThread *m_pCameraThread = nullptr;


    Mat    m_mat;
};

#endif // COPENCVBASE_H
