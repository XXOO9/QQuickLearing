#ifndef CCAMERATHREADCONTROLER_H
#define CCAMERATHREADCONTROLER_H

#include <QObject>
#include "COpencvBase.h"

class CCameraThreadControler : public QObject
{
    Q_OBJECT
public:
    explicit CCameraThreadControler(QObject *parent = nullptr );

private:
    void init();

signals:
    void sigOpenCamera();
    void sigCloseCamera();
    void sigNewImageAvailable( const QImage &srcImg );

private:
    COpencvBase m_camera;
};

#endif // CCAMERATHREADCONTROLER_H
