#ifndef CFFMPEGAUDIODECODER_H
#define CFFMPEGAUDIODECODER_H

#include <QObject>
#include <QDebug>
#include <QQueue>
#include <QVideoFrame>
#include "CAudioPlayer.h"

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

    void startDecodeAudio( const QString &fileName );

    void startPlay();

    CAudioPlayer    *m_pAudioPlayer = nullptr;
    QAudioOutput *out = nullptr;
};

#endif // CFFMPEGAUDIODECODER_H
