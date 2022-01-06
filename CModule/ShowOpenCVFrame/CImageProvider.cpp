#include "CImageProvider.h"

CImageProvider::CImageProvider() : QQuickImageProvider ( QQuickImageProvider::Image )
{

}

CImageProvider::~CImageProvider()
{

}

QImage CImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED( id )
    Q_UNUSED( size )
    Q_UNUSED( requestedSize )

    QMutexLocker locker(&m_mutex);
    QImage tmpImage = m_imgCurFrame;
    return tmpImage;
}

QPixmap CImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED( id )
    Q_UNUSED( size )
    Q_UNUSED( requestedSize )

    QMutexLocker locker(&m_mutex);
    QPixmap pixMap = QPixmap::fromImage( m_imgCurFrame );
    return pixMap;
}

void CImageProvider::setImage(QImage image)
{

}
