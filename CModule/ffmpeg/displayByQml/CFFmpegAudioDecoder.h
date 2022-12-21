#ifndef CFFMPEGAUDIODECODER_H
#define CFFMPEGAUDIODECODER_H

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

class CFFmpegAudioDecoder : public QObject
{
    Q_OBJECT
public:
    explicit CFFmpegAudioDecoder(QObject *parent = nullptr);
    virtual ~CFFmpegAudioDecoder() override;

signals:

public slots:
    void onStartDecodeAudio();

private:
    void initAudioDecoder();

private:
    QString             m_videoFileName = "";
    AVFormatContext    *m_pFmtCtx       = nullptr;
    AVCodecContext     *m_pCodeCtx      = nullptr;
    AVCodecParameters  *m_pCodePara     = nullptr;
    AVCodec            *m_pCodec        = nullptr;
    AVPacket           *m_pPkt          = nullptr;
};

#endif // CFFMPEGAUDIODECODER_H
