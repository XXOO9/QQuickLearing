#ifndef VIDEODECODER_H
#define VIDEODECODER_H

#include <QThread>
#include <QObject>
#include <QDebug>

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

class videoDecoder : public QThread
{
    Q_OBJECT
public:
    videoDecoder();
    virtual ~videoDecoder() override;

    void setVideoPath( const QString &filePath );

    Q_INVOKABLE void startPlay();

    void displayVideoInfos( AVFormatContext *fmtCtx );

signals:
    void sigNewFrameAvailable( QImage &newFrameImg );

private:
    void init();

protected:
    virtual void run() override;

private:
    AVFrame *m_pFrame = nullptr;
    AVFormatContext     *m_pFmtCtx = nullptr;
    QString              m_curPlayFileName;
    int                  m_videoStreamIndex = -1;
};

#endif // VIDEODECODER_H
