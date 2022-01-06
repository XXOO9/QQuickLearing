#ifndef CDEVCAMERACONTROL_H
#define CDEVCAMERACONTROL_H

#include <QObject>
#include "CDevCamera.h"
#include "CImageProvider.h"

class CDevCameraControl : public QObject
{
    Q_OBJECT
public:
    explicit CDevCameraControl(QObject *parent = nullptr);
    virtual ~CDevCameraControl() override;

    void init();
    void initConnection();

    void openCamera();
    void closeCamera();

    CImageProvider *imgProvider() const;
    void setPImgProvider(CImageProvider *imgProvider);

signals:
    Q_INVOKABLE void sigImgProviderReadyFresh();

public slots:
    void onNewImageAvaliable( QImage img );

private:
    CDevCamera      *m_pDevCamera;
    CImageProvider  *m_pImgProvider;
};

#endif // CDEVCAMERACONTROL_H
