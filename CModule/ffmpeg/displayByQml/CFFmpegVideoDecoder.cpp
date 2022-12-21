#include "CFFmpegVideoDecoder.h"

CFFmpegVideoDecoder::CFFmpegVideoDecoder(QObject *parent) : QObject(parent)
{
    initDecoder();
}

CFFmpegVideoDecoder::~CFFmpegVideoDecoder()
{

}

QVideoFrame::PixelFormat CFFmpegVideoDecoder::converFFmpegPixelFmt2QVideoFrameFormat(const AVPixelFormat &srcFmt)
{
    switch ( srcFmt ) {
    case AVPixelFormat::AV_PIX_FMT_YUV420P:
    case AVPixelFormat::AV_PIX_FMT_YUVJ420P:
        return QVideoFrame::Format_YUV420P;

    case AVPixelFormat::AV_PIX_FMT_NV12:
        return QVideoFrame::Format_NV12;

    default:
        return QVideoFrame::Format_Invalid;
    }
}

void CFFmpegVideoDecoder::onStartDecodeVideoFrame()
{
    //视频流下标
    int videoStreamIndex = 0;

    //打开文件
    if( avformat_open_input( &m_pFmtCtx, m_videoFileName.toStdString().c_str(), nullptr, nullptr ) != 0 ){
        qDebug() << "open targget video file failed...";
        return;
    }

    //解析视频流信息,关联上下文信息
    if( avformat_find_stream_info( m_pFmtCtx, nullptr ) < 0 ){
        return;
    }

    //寻找视频流
    for( unsigned int streamIndex = 0; streamIndex < m_pFmtCtx->nb_streams; streamIndex++ ){
        if( m_pFmtCtx->streams[ streamIndex ]->codec->codec_type == AVMEDIA_TYPE_VIDEO ){
            videoStreamIndex = streamIndex;
            break;
        }
    }

    //根据视频流信息配置解码环境, 先配置解码参数，在配置解码器, 根据解码参数m_pCodePara的解码ID来配置解码器
    m_pCodePara = m_pFmtCtx->streams[ videoStreamIndex ]->codecpar;
    m_pCodec    = avcodec_find_decoder( m_pCodePara->codec_id );

    //如果没找到，会返回空指针
    if( nullptr == m_pCodec ){
        qDebug() << "can't find decoder...";
        return;
    }

    //如果找到了对应的解码器，则直接配置解码器
    m_pCodeCtx = avcodec_alloc_context3( m_pCodec );

    //将解码器和解码参数匹配起来
    avcodec_parameters_to_context( m_pCodeCtx, m_pCodePara );

    if( avcodec_open2( m_pCodeCtx, m_pCodec, nullptr ) < 0 ){
        return;
    }

    int width = m_pCodeCtx->width;
    int height = m_pCodeCtx->height;

    m_pPkt = av_packet_alloc();
    int ret = av_new_packet( m_pPkt, width * height );


    while( av_read_frame( m_pFmtCtx, m_pPkt ) >= 0 ){
        if( m_pPkt->stream_index != videoStreamIndex ){
            continue;
        }

        if( avcodec_send_packet( m_pCodeCtx, m_pPkt ) < 0 ){
            continue;
        }

        while( avcodec_receive_frame( m_pCodeCtx, m_pAVFrame ) >= 0 ){
            decodeVideoFrame( m_pAVFrame );
        }

        av_packet_unref( m_pPkt );
    }


    av_packet_free( &m_pPkt );
    avcodec_close( m_pCodeCtx );
    avcodec_parameters_free( &m_pCodePara );
    av_frame_free( &m_pAVFrame );
}

void CFFmpegVideoDecoder::initDecoder()
{
    //初始化指针
    m_pFmtCtx = avformat_alloc_context();
}

void CFFmpegVideoDecoder::decodeVideoFrame(const AVFrame *pFrame)
{
    int imgSize = av_image_get_buffer_size( static_cast<AVPixelFormat>( pFrame->format ), pFrame->width, pFrame->height, 1 );
    QSize frameSize( pFrame->width, pFrame->height );
    QVideoFrame::PixelFormat frameFormat = converFFmpegPixelFmt2QVideoFrameFormat( static_cast<AVPixelFormat>( pFrame->format ));

    QVideoFrame tmpFrame( imgSize, frameSize, pFrame->width, frameFormat );

    //GPU形式的内存映射到CPU形式的内存
    if( tmpFrame.map( QAbstractVideoBuffer::WriteOnly ) ){
        av_image_copy_to_buffer( tmpFrame.bits(), imgSize, pFrame->data,
                                 pFrame->linesize, static_cast<AVPixelFormat>( pFrame->format ), pFrame->width, pFrame->height, 1 );

        tmpFrame.unmap();
        tmpFrame.setStartTime( 0 );
    }
}
