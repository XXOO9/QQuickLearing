#ifndef CVIDEOFRAMEPROVIDER_H
#define CVIDEOFRAMEPROVIDER_H

#include <QObject>
#include <QDebug>
#include <QAbstractVideoSurface>


class CVideoFrameProvider : public QObject
{
    Q_OBJECT
public:
    explicit CVideoFrameProvider(QObject *parent = nullptr);
    virtual ~CVideoFrameProvider() override;


private:
};

#endif // CVIDEOFRAMEPROVIDER_H
