#ifndef CFFMPEGLEVEL1_H
#define CFFMPEGLEVEL1_H

#include <QObject>
#include <QDebug>

extern "C"{
   #include "libavcodec/avcodec.h"
   #include "libavformat/avformat.h"
   #include "libswscale/swscale.h"
   #include "libavdevice/avdevice.h"
}

class CFFmpegLevel1 : public QObject
{
    Q_OBJECT
public:
    explicit CFFmpegLevel1(QObject *parent = nullptr);


private:
    void displayFFmpegVersion();

    void displayVideoInfos();

    void decodeVideoStream();
};

#endif // CFFMPEGLEVEL1_H
