#include "CFFmpegLevel1.h"

CFFmpegLevel1::CFFmpegLevel1(QObject *parent)
    : QObject{parent}
{
    //    displayFFmpegVersion();

    decodeVideoStream();
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

    int ret = avformat_open_input( &fmt_ctx, fileName, nullptr, nullptr );

    //如果打开文件失败
    if( ret < 0 ){
        qDebug() << "can't open file...";
    }else{
        ret = avformat_find_stream_info( fmt_ctx, nullptr );
        if( ret < 0 ){
            qDebug() << "can't find stream with given path...";
        }else{
            qDebug() << "find stream info!";
            av_dump_format( fmt_ctx, 0, fileName, 0 );
        }

        avformat_close_input( &fmt_ctx );
    }
}

void CFFmpegLevel1::decodeVideoStream()
{
    //视频流所在流序列中的索引
    int videoStreamIndex = -1;

    int ret = 0;

    AVFormatContext     *fmt_ctx = nullptr;
    AVPacket            *pkt = nullptr;
    AVCodecContext      *codecCtx = nullptr;
    AVCodecParameters   *codecParameters = nullptr;
    AVCodec             *codec = nullptr;
    AVFrame             *yuvFrame = av_frame_alloc();
    AVFrame             *rgbFrame = av_frame_alloc();

    do{
        //创建AVFormatContext 结构体
        fmt_ctx = avformat_alloc_context();

        //打开文件
        ret = avformat_open_input( &fmt_ctx, fileName, nullptr, nullptr );

        if( ret != 0 ){
            qDebug() << "open video failed..";
            break;
        }

        //获取视频流信息
        ret = avformat_find_stream_info( fmt_ctx, nullptr );
        if( ret < 0 ){
            qDebug() << "can't find video streams...";
            break;
        }

        //循环查找视频流中的信息,知道查找到视频类型的流
        //找到后, 赋值到 videoStreamIndex

        for(unsigned int i = 0; i < fmt_ctx->nb_streams; i++ ){
            if( fmt_ctx->streams[ i ]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO ){
                videoStreamIndex = i;
                break;
            }
        }

        if( videoStreamIndex == -1 ){
            qDebug() << "can't find video stream infos...";
            break;
        }

        av_dump_format( fmt_ctx, 0, fileName, 0 );

        //查找解码器
        codecParameters = fmt_ctx->streams[ videoStreamIndex ]->codecpar;
        codec = avcodec_find_decoder( codecParameters->codec_id );

        if( codec == nullptr ){
            qDebug() << "can't find codec ...";
            break;
        }

        //根据解码器参数来创建解码器内容
        codecCtx = avcodec_alloc_context3( codec );
        avcodec_parameters_to_context( codecCtx, codecParameters );

        if( codecCtx == nullptr ){
            qDebug() << "can't alloc codec context...";
            break;
        }

        //打开解码器
        ret = avcodec_open2( codecCtx, codec, nullptr );

        if( ret < 0 ){
            qDebug() << "open codec failed...";
            break;
        }

        //设置转换参数
        struct SwsContext *img_ctx = sws_getContext( codecCtx->width, codecCtx->height, codecCtx->pix_fmt,
                                                     codecCtx->width, codecCtx->height, AV_PIX_FMT_RGB32,
                                                     SWS_BICUBIC, nullptr, nullptr, nullptr );
        //分配空间
        int numBytes = av_image_get_buffer_size( AV_PIX_FMT_RGB32, codecCtx->width, codecCtx->height, 1 );
        unsigned char *out_buffer = ( unsigned char* )av_malloc( numBytes * sizeof( unsigned char* ) );

        //分配AVPacket 结构体

        //用于计数帧数
        int i  = 0;
        pkt = av_packet_alloc();
        av_new_packet( pkt, codecCtx->width * codecCtx->height );

        //读取视频信息
        while( av_read_frame( fmt_ctx, pkt ) >= 0 )
        {
            if( pkt->stream_index == videoStreamIndex ){
                //只计数视频帧
                i++;

                ret = avcodec_send_packet( codecCtx, pkt );
                if( ret == 0 ){
                    while( avcodec_receive_frame( codecCtx, yuvFrame ) == 0 ){
                        if (++i <= 500 && i >= 455){
                            sws_scale(img_ctx,
                                      (const uint8_t* const*)yuvFrame->data,
                                      yuvFrame->linesize,
                                      0,
                                      codecCtx->height,
                                      rgbFrame->data,
                                      rgbFrame->linesize);
                            saveFrame(rgbFrame, codecCtx->width, codecCtx->height, i );
                        }
                    }
                }

                //充值pkt
                av_packet_unref( pkt );
            }
        }

        qDebug() << "there are " << i << "frames in total...";
    }while( 0 );

    av_packet_free( &pkt );
    avcodec_close( codecCtx );
    avcodec_parameters_free( &codecParameters );
    avformat_close_input( &fmt_ctx );
    avformat_free_context( fmt_ctx );

    av_free( codec );
}

void CFFmpegLevel1::saveFrame(AVFrame *pFrame, int width, int height, int frame)
{
    FILE    *pFile = nullptr;
    char    szFileName[32];
    int y;

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





