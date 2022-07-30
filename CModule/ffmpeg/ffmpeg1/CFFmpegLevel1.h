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
    //测试输出ffmpeg的版本号
    void displayFFmpegVersion();

    //测试输出视频详细信息
    void displayVideoInfos();

    //测试保存一帧为图片
    void decodeVideoStream();
    //921,600 + 230400

private:
    void saveFrame( AVFrame *pFrame, int width, int height, int frame );

};

#endif // CFFMPEGLEVEL1_H
