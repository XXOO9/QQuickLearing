#ifndef CIMAGEPROVIDER_H
#define CIMAGEPROVIDER_H

#include <QMutex>
#include <QMutexLocker>
#include <QQuickImageProvider>

//要在QML中显示来自于C++的图像，必须用一个类继承于QQuickImageProvider,

class CImageProvider : public QQuickImageProvider
{
public:
    CImageProvider();
    virtual ~CImageProvider() override;


    virtual QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;

    void setImage( const QImage image );

private:
    QImage m_imgCurFrame;
    QMutex m_mutex;


};

#endif // CIMAGEPROVIDER_H
