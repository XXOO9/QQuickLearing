#include "videoDecoder.h"

videoDecoder::videoDecoder()
{

}

videoDecoder::~videoDecoder()
{

}

void videoDecoder::setVideoPath(const QString &filePath)
{
    m_curPlayFileName = filePath;
}

void videoDecoder::startPlay()
{
    qDebug() << "start...";
}

void videoDecoder::displayVideoInfos(AVFormatContext *fmtCtx)
{
    av_dump_format( fmtCtx, 0, nullptr, 0 );
}

void videoDecoder::init()
{
    //初始化ffmpeg 环境
    m_pFmtCtx = avformat_alloc_context();
}

void videoDecoder::run()
{
    m_curPlayFileName = "D:/videos/CFD.mp4";
    //检查文件是否有效
    if( m_curPlayFileName.isEmpty() ){
        return;
    }

    //打开文件
    if( avformat_open_input( &m_pFmtCtx, m_curPlayFileName.toLocal8Bit().data(), nullptr, nullptr ) != 0 ){
        qDebug() << "open specific file failed...";
        return;
    }

    //打印视频详细信息
    displayVideoInfos( m_pFmtCtx );

    //获取视频流信息
    m_videoStreamIndex = avformat_find_stream_info( m_pFmtCtx, nullptr );

    if( m_videoStreamIndex < 0 ){
        qDebug() << "find video stream failed...";
        return;
    }






}
