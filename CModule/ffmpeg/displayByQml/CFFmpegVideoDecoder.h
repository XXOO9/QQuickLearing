#ifndef CFFMPEGVIDEODECODER_H
#define CFFMPEGVIDEODECODER_H

/*
 * 视频解码放置在线程中运行， 解码时不用全部解析完，根据实际情况解码对应的帧数
*/

#include <QObject>
#include <QDebug>
#include <QQueue>
#include <QVideoFrame>

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

class CFFmpegVideoDecoder : public QObject
{
    Q_OBJECT
public:
    explicit CFFmpegVideoDecoder(QObject *parent = nullptr);
    virtual ~CFFmpegVideoDecoder() override;

    static QVideoFrame::PixelFormat converFFmpegPixelFmt2QVideoFrameFormat( const AVPixelFormat &srcFmt );

signals:

public slots:
    void onStartDecodeVideoFrame();
private:
    void initDecoder();
    void decodeVideoFrame( const AVFrame *pFrame );
private:
    QString             m_videoFileName = "";
    AVFormatContext    *m_pFmtCtx       = nullptr;
    AVCodecContext     *m_pCodeCtx      = nullptr;
    AVCodecParameters  *m_pCodePara     = nullptr;
    AVCodec            *m_pCodec        = nullptr;
    AVPacket           *m_pPkt          = nullptr;
    AVFrame            *m_pAVFrame      = nullptr;
};

#endif // CFFMPEGVIDEODECODER_H
