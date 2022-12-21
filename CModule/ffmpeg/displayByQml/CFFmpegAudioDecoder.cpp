#include "CFFmpegAudioDecoder.h"

CFFmpegAudioDecoder::CFFmpegAudioDecoder(QObject *parent) : QObject(parent)
{
    initAudioDecoder();
}

CFFmpegAudioDecoder::~CFFmpegAudioDecoder()
{

}

void CFFmpegAudioDecoder::onStartDecodeAudio()
{

}

void CFFmpegAudioDecoder::initAudioDecoder()
{
    const char *fileName = "./test.mp3";
    int audioStreamIndex = -1;

    FILE *file = fopen( "test.pcm", "wb+" );

    if( nullptr == file ){
        return;
    }

    AVFormatContext       *pAvFmtContext = nullptr;
    AVCodec               *pCodec        = nullptr;
    AVCodecParameters     *pCodecPara    = nullptr;
    AVCodecContext        *pCodecCtx     = nullptr;
    AVPacket              *pkt           = av_packet_alloc();
    AVFrame               *pFrame        = av_frame_alloc();

    pAvFmtContext = avformat_alloc_context();

    if( avformat_open_input( &pAvFmtContext, fileName, nullptr, nullptr ) < 0 ){
        return;
    }

    if( avformat_find_stream_info( pAvFmtContext, nullptr ) < 0 ){
        return;
    }

    for( unsigned int streamIndex = 0; streamIndex < pAvFmtContext->nb_streams; streamIndex++ ){
        if( pAvFmtContext->streams[ streamIndex ]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO ){
            audioStreamIndex = streamIndex;
            break;
        }
    }

    if( audioStreamIndex < 0 ){
        return;
    }


    pCodecPara = pAvFmtContext->streams[ audioStreamIndex ]->codecpar;
    pCodec = avcodec_find_decoder( pCodecPara->codec_id );

    if( nullptr == pCodec ){
        return;
    }

    pCodecCtx = avcodec_alloc_context3( pCodec );

    if( avcodec_parameters_to_context( pCodecCtx, pCodecPara ) < 0 ){
        return;
    }


    pCodecCtx->pkt_timebase = pAvFmtContext->streams[ audioStreamIndex ]->time_base;

    if( avcodec_open2( pCodecCtx, pCodec, nullptr ) < 0 ){
        return;
    }

    av_packet_unref( pkt );
    while( av_read_frame( pAvFmtContext, pkt ) >= 0 ){
        if( pkt->stream_index == audioStreamIndex ){
            int ret = avcodec_send_packet( pCodecCtx, pkt );

            if( ret < 0 ){
                qDebug() << "error1";
                continue;
            }

            ret = avcodec_receive_frame( pCodecCtx, pFrame );

            if( ret < 0 ){
                qDebug() << "error2";
                continue;
            }

            int numberBytes = av_get_bytes_per_sample( pCodecCtx->sample_fmt );

            if( numberBytes < 0 ){
                continue;
            }

            if( av_sample_fmt_is_planar( pCodecCtx->sample_fmt ) ){
                for( int i = 0; i < pFrame->nb_samples; i++ ){
                    for( int ch = 0; ch < pFrame->channels; ch++ ){
                        fwrite( (char*)pFrame->data[ch] + numberBytes * i, 1, numberBytes, file );
                    }
                }
            }


        }

        av_packet_unref( pkt );
    }


    av_frame_free( &pFrame );
    av_packet_free( &pkt );
    avcodec_close( pCodecCtx );
    avcodec_free_context( &pCodecCtx );
    avformat_free_context( pAvFmtContext );

    fclose( file );

    qDebug() << "done...";





}
