#ifndef CFFMPEGLEVEL1_H
#define CFFMPEGLEVEL1_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QVideoFrame>
#include <QVideoSurfaceFormat>


extern "C"{
#include "libavcodec/avcodec.h"
#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libavutil/ffversion.h"
#include "libswresample/swresample.h"
#include "libswscale/swscale.h"
#include "libpostproc/postprocess.h"
#include "libavutil/imgutils.h"
}

class CFFmpegLevel1 : public QObject
{
    Q_OBJECT
public:
    explicit CFFmpegLevel1(QObject *parent = nullptr);

signals:
    void sigNewFrameAvailable( const QVideoFrame &frame );


public:
    //测试输出ffmpeg的版本号
    void displayFFmpegVersion();

    //测试输出视频详细信息
    void displayVideoInfos();


    //测试保存一帧为图片
    void saveEachFrame();
    //921,600 + 230400

    //解码视频流
    void decodecVideoStream();

    void savePerFrameAsYUV420();

    static QVideoFrame::PixelFormat convertFFmpegFor2QtVideoFormat( const AVPixelFormat &ffmpegFmt );


private:
    void saveFrame( AVFrame *pFrame, int width, int height, int frame );
    void sss( const AVFrame *frame, int pixFmt );


    const char *m_fileName = "D:/videos/CFD.mp4";

};

#endif // CFFMPEGLEVEL1_H
