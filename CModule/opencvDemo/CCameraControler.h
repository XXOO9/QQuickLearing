#ifndef CCAMERACONTROLER_H
#define CCAMERACONTROLER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

class CCameraControler : public QObject
{
    Q_OBJECT
public:
    explicit CCameraControler(QObject *parent = nullptr);
    virtual ~CCameraControler() override;



signals:
    void insideSigOpenCamera();

public slots:
    void openCamera();

private:
    void init();
    void initThread();
    void initInsideConnection();

private:
    VideoCapture m_camera;
    Mat          m_frame;
    QThread     *m_pCameraThread = nullptr;
};

#endif // CCAMERACONTROLER_H
