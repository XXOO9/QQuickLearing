#include "CFFmpegLevel1.h"

CFFmpegLevel1::CFFmpegLevel1(QObject *parent)
    : QObject{parent}
{
//    displayFFmpegVersion();

//    saveEachFrame();
//    savePerFrameAsYUV420();
}

void CFFmpegLevel1::displayFFmpegVersion()
{
    unsigned ffmpegVersion = avcodec_version();
    qDebug() << "ffmpeg version = " << ffmpegVersion;
}

void CFFmpegLevel1::displayVideoInfos()
{
    //创建对象
    AVFormatContext *fmt_ctx = avformat_alloc_context();

    int ret = avformat_open_input( &fmt_ctx, m_fileName, nullptr, nullptr );

    //如果打开文件失败
    if( ret < 0 ){
        qDebug() << "can't open file...";
    }else{
        ret = avformat_find_stream_info( fmt_ctx, nullptr );
        if( ret < 0 ){
            qDebug() << "can't find stream with given path...";
        }else{
            qDebug() << "find stream info!";
            av_dump_format( fmt_ctx, 0, m_fileName, 0 );
        }

        avformat_close_input( &fmt_ctx );
    }
}

void CFFmpegLevel1::saveEachFrame()
{
    const char *videoFileName = "D:/videos/CFD.mp4";
    int videoStreamIndex = -1;

    AVFormatContext   *fmtCtx      = nullptr;
    AVPacket          *pkt         = nullptr;
    AVCodecParameters *avcodecPara = nullptr;
    AVCodec           *codec       = nullptr;
    AVCodecContext    *codeCtx     = nullptr;
    AVFrame           *yuvFrame    = av_frame_alloc();
    AVFrame           *rgbFrame    = av_frame_alloc();

    fmtCtx = avformat_alloc_context();

    int ret = avformat_open_input( &fmtCtx, videoFileName, nullptr, nullptr );

    if( ret < 0 ){
        return;
    }

    ret = avformat_find_stream_info( fmtCtx, nullptr);
    if( ret < 0 ){
        return;
    }

    for( unsigned int index = 0; index < fmtCtx->nb_streams; index++ ){
        if( fmtCtx->streams[ index ]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO ){
            videoStreamIndex = index;
            break;
        }
    }

    avcodecPara = fmtCtx->streams[ videoStreamIndex ]->codecpar;
    codec       = avcodec_find_decoder( avcodecPara->codec_id );

    if( nullptr == codec ){
        return;
    }

    codeCtx = avcodec_alloc_context3( codec );

    avcodec_parameters_to_context( codeCtx, avcodecPara );

    if( nullptr == codeCtx ){
        return;
    }

    if( avcodec_open2( codeCtx, codec, nullptr ) < 0 ){
        return;
    }

    struct SwsContext *img_ctx = sws_getContext( codeCtx->width, codeCtx->height, codeCtx->pix_fmt,
                                                 codeCtx->width, codeCtx->height, AV_PIX_FMT_RGB32,
                                                 SWS_BICUBIC, nullptr, nullptr, nullptr );

    int perFrameSize = av_image_get_buffer_size( AV_PIX_FMT_RGB32, codeCtx->width, codeCtx->height, 1 );
    unsigned char *out_buffer = ( unsigned char* )av_malloc( perFrameSize * sizeof( unsigned char ) );

    int frameCnt = 0;
    pkt = av_packet_alloc();
    av_new_packet( pkt, codeCtx->width * codeCtx->height );

    av_image_fill_arrays( rgbFrame->data, rgbFrame->linesize, out_buffer, AV_PIX_FMT_RGB32,
                          codeCtx->width, codeCtx->height, 1 );

    while( av_read_frame( fmtCtx, pkt ) >= 0 ){
        if( pkt->stream_index == videoStreamIndex ){
            if( avcodec_send_packet( codeCtx, pkt ) >= 0 ){
                while( avcodec_receive_frame( codeCtx, yuvFrame ) >= 0 ){
                    frameCnt++;
                    sws_scale( img_ctx, ( const uint8_t* const*) yuvFrame->data,
                               yuvFrame->linesize, 0, codeCtx->height, rgbFrame->data, rgbFrame->linesize );
                    saveFrame( rgbFrame, codeCtx->width, codeCtx->height, frameCnt );

                }
            }
        }

        av_packet_unref( pkt );
    }

    av_packet_free( &pkt );

    avcodec_close( codeCtx );
    avcodec_parameters_free( &avcodecPara );
    avformat_close_input( &fmtCtx );
    avformat_free_context( fmtCtx );
    av_frame_free( &yuvFrame );
    av_frame_free( &rgbFrame );

}

void CFFmpegLevel1::decodecVideoStream()
{
    //视频文件名
    const char *videoFileName = "D:/videos/CFD.mp4";

    //视频流所在的流索引
    int videoStreamIndex = -1;

    //
    int ret = 0;

    AVFormatContext     *fmtCtx = nullptr;
    AVPacket            *pkt = nullptr;
    AVCodecContext      *codecCtx = nullptr;
    AVCodecParameters   *avCodecPara = nullptr;
    AVCodec             *codec = nullptr;

    //1.创建AVFormatContext 结构体指针, ffmpeg所有的操作都是通过AVFormatContext来完成的
    fmtCtx = avformat_alloc_context();

    //2.打开视频流文件
    ret = avformat_open_input( &fmtCtx, videoFileName, nullptr, nullptr );

    if( ret != 0 ){
        qDebug() << "can't open video file...";
        return;
    }

    //3.获取视频流信息
    ret = avformat_find_stream_info( fmtCtx, nullptr );

    if( ret < 0 ) {
        qDebug() << "can't get video stream info...";
        return;
    }


    //4.循环查找视频流中包含的流信息，直到找到视频流,并且记录改视频流下标到videoStreamIndex中
    for( unsigned int i = 0; i < fmtCtx->nb_streams; i++ ){
        if( fmtCtx->streams[ i ]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO ){
            videoStreamIndex = i;
            break;
        }
    }

    //5.如果没有找到视频流就退出
    if( videoStreamIndex == -1 ){
        qDebug() << "can't find video stream info...";
        return;
    }

    //6.如果找到了视频流，就开始查找对应的解码器
    avCodecPara = fmtCtx->streams[ videoStreamIndex ]->codecpar;
    codec = avcodec_find_decoder( avCodecPara->codec_id );

    if( nullptr ==  codec ){
        qDebug() << "can't find decoder...";
        return;
    }

    //根据解码器参数来创建解码器内容
    codecCtx = avcodec_alloc_context3( codec );
    avcodec_parameters_to_context( codecCtx, avCodecPara );

    if( nullptr == codecCtx ){
        qDebug() << "can't alloc codec context...";
        return;
    }

    //打开解码器
    ret = avcodec_open2( codecCtx, codec, nullptr );
    if( ret < 0 ){
        qDebug() << "can't open decoeder...";
        return;
    }

    //分配AVPacket结构体
    pkt = av_packet_alloc();

    //计数帧数
    int frameCnt = 0;

    //调整pkt数据
    av_new_packet( pkt, codecCtx->width * codecCtx->height );

    //依次读取视频信息
    while( av_read_frame( fmtCtx, pkt) >= 0 ){
        if( pkt->stream_index == videoStreamIndex ){
            //只计数视频帧
            frameCnt++;
        }

        //重置pkt
        av_packet_unref( pkt );
    }

    qDebug() << "there are " << frameCnt << " frames in video";

    //释放所有指针
    av_packet_free( &pkt );
    avcodec_close( codecCtx );
    avcodec_parameters_free( &avCodecPara );
    avformat_close_input( &fmtCtx );
    avformat_free_context( fmtCtx );

    av_free( codec );
}

void CFFmpegLevel1::savePerFrameAsYUV420()
{
    printf( "start...\n" );
    FILE    *fp = fopen( "./result.yuv", "wb+" );
    if( nullptr == fp ){
        return;
    }

    const char *fileName = m_fileName;
    int videoStreamIndex = -1;

    AVFormatContext     *fmtCtx = nullptr;
    AVCodecContext      *avCodecCtx = nullptr;
    AVCodec             *codec     = nullptr;
    AVCodecParameters   *avCodecPara = nullptr;
    AVPacket            *pkt = nullptr;
    AVFrame             *yuvFrame = av_frame_alloc();

    fmtCtx = avformat_alloc_context();

    int ret = avformat_open_input(&fmtCtx, fileName, nullptr, nullptr );

    if( ret < 0 ) {
        return;
    }

    if( avformat_find_stream_info( fmtCtx, nullptr ) <0 ){
        return;
    }

    for( unsigned int index = 0; index < fmtCtx->nb_streams; index++ ){
        if( fmtCtx->streams[ index ]->codec->codec_type == AVMEDIA_TYPE_VIDEO ){
            videoStreamIndex = index;
            break;
        }
    }

    if( videoStreamIndex < 0 ){
        return;
    }

    avCodecPara = fmtCtx->streams[ videoStreamIndex ]->codecpar;
    codec =avcodec_find_decoder( avCodecPara->codec_id );

    if( nullptr == codec ){
        return;
    }

    avCodecCtx = avcodec_alloc_context3( codec );
    avcodec_parameters_to_context( avCodecCtx, avCodecPara );

    if( avcodec_open2( avCodecCtx, codec, nullptr ) < 0 ){
        return;
    }

    int width = avCodecCtx->width;
    int height = avCodecCtx->height;

    pkt = av_packet_alloc();
    ret = av_new_packet( pkt, width * height );

    int cnt = 0;

    while( av_read_frame( fmtCtx, pkt ) >= 0 ){
        if( pkt->stream_index == videoStreamIndex ){
            if( avcodec_send_packet( avCodecCtx, pkt ) == 0 ){
                while( avcodec_receive_frame( avCodecCtx, yuvFrame ) == 0 ){
                    cnt++;
//                    fwrite( yuvFrame->data[ 0 ], 1, width * height, fp );// y
//                    fwrite( yuvFrame->data[ 1 ], 1, width * height / 4, fp );// u
//                    fwrite( yuvFrame->data[ 2 ], 1, width * height / 4, fp );// v

                    int imgSize = av_image_get_buffer_size( static_cast<AVPixelFormat>( yuvFrame->format ), yuvFrame->width, yuvFrame->height, 1 );
                    QSize   frameSize = QSize( yuvFrame->width, yuvFrame->height );
                    QVideoFrame::PixelFormat fmt = QVideoFrame::Format_YUV420P;

                    QVideoFrame frame( imgSize, frameSize, yuvFrame->width, fmt );

                    if(frame.map( QAbstractVideoBuffer::WriteOnly ) ){
                        int ret = av_image_copy_to_buffer( frame.bits(), imgSize, yuvFrame->data,
                                                           yuvFrame->linesize, (AVPixelFormat)yuvFrame->format, yuvFrame->width, yuvFrame->height, 1 );

                        frame.unmap();
                        frame.setStartTime( 0 );

                        emit sigNewFrameAvailable( frame );
//                        QThread::msleep( 200 );
                    }
                }
            }
        }

        av_packet_unref( pkt );
    }
    qDebug() << cnt << " frames";

    av_packet_free( &pkt );
    avcodec_close( avCodecCtx );
    avcodec_parameters_free( &avCodecPara );
    av_frame_free( &yuvFrame );

    printf( "done...\n" );

}

QVideoFrame::PixelFormat CFFmpegLevel1::convertFFmpegFor2QtVideoFormat(const AVPixelFormat &ffmpegFmt)
{
    switch( ffmpegFmt ){
    case AVPixelFormat::AV_PIX_FMT_YUV420P:
    case AVPixelFormat::AV_PIX_FMT_YUVJ420P:
        return QVideoFrame::Format_YUV420P;

    case AVPixelFormat::AV_PIX_FMT_NV12:
        return QVideoFrame::Format_NV12;

    default:
        return QVideoFrame::Format_Invalid;
    }
}

void CFFmpegLevel1::saveFrame(AVFrame *pFrame, int width, int height, int frame)
{
    FILE    *pFile = nullptr;
    char    szFileName[32];
    int y = 0;

    //打开文件
    sprintf( szFileName, "frame%d.ppm", frame );

    pFile = fopen( szFileName, "wb" );

    if( nullptr == pFile ){
        return;
    }

    //写入文件头
    fprintf( pFile, "P6\n%d %d\n255\n", width, height );

    //写入像素数据
    for( y = 0; y < height; y++ ){
        fwrite( pFrame->data[ 0 ] + y * pFrame->linesize[ 0 ], 1, width * 3, pFile );
    }

    fclose( pFile );
}

void CFFmpegLevel1::sss(const AVFrame *frame, int pixFmt)
{

}





