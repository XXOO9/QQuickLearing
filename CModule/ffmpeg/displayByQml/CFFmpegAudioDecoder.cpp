#include "CFFmpegAudioDecoder.h"

CFFmpegAudioDecoder::CFFmpegAudioDecoder(QObject *parent) : QObject(parent)
{
//    startDecodeAudio( "D:/videos/CFD.mp4" );
//    startDecodeAudio( "./test.mp3" );
}

CFFmpegAudioDecoder::~CFFmpegAudioDecoder()
{

}

void CFFmpegAudioDecoder::startDecodeAudio(const QString &fileName)
{
    AVFormatContext *pFmtCtx = avformat_alloc_context();

    int ret = avformat_open_input( &pFmtCtx, fileName.toStdString().c_str(), nullptr, nullptr );

    if( ret < 0 ){
        qDebug() << "open src file failed...";
        return;
    }

    if( avformat_find_stream_info( pFmtCtx, nullptr ) < 0 ){
        qDebug() << "can't find stream infos...";
        return;
    }

    int audioStreamIndex = -1;

    for( unsigned int index = 0; index < pFmtCtx->nb_streams; index++ ){
        if( AVMediaType::AVMEDIA_TYPE_AUDIO == pFmtCtx->streams[ index ]->codec->codec_type ){
            audioStreamIndex = index;
            break;
        }
    }

    AVCodecParameters   *pCodecParam = pFmtCtx->streams[ audioStreamIndex ]->codecpar;
    AVCodec             *pCodec      = avcodec_find_decoder( pCodecParam->codec_id );

    if( nullptr == pCodec ){
        qDebug() << "can't find decoder...";
        return;
    }

    AVCodecContext  *pCodecCtx = avcodec_alloc_context3( pCodec );
    if( avcodec_parameters_to_context( pCodecCtx, pCodecParam ) < 0 ){
        qDebug() << "can't codec parameters to context...";
        return;
    }

    if( avcodec_open2( pCodecCtx, pCodec, nullptr ) < 0 ){
        qDebug() << "can't open input2...";
        return;
    }

    enum AVSampleFormat in_sample_fmt = pCodecCtx->sample_fmt;
    int  inSampleRate                 = pCodecCtx->sample_rate;

    qDebug() << "fmt = " << in_sample_fmt;
    qDebug() << "sample rate = " << inSampleRate;

    FILE    *fd = fopen( "ret.pcm", "wb+" );

    AVPacket        *pPkt      = av_packet_alloc();
    AVFrame         *pFrame    = av_frame_alloc();


    bool resample = true;

    //设置重采样参数
    uint64_t out_channel_layout = pCodecCtx->channel_layout;
    enum AVSampleFormat outSampleFmt = AVSampleFormat::AV_SAMPLE_FMT_S16;
    int outSampleRate                = pCodecCtx->sample_rate;
    int outChannels                  = av_get_channel_layout_nb_channels( out_channel_layout );

    SwrContext  *swsCtx = swr_alloc_set_opts( nullptr, out_channel_layout, outSampleFmt, outSampleRate, pCodecCtx->channel_layout,
                                              pCodecCtx->sample_fmt, pCodecCtx->sample_rate, 0, nullptr );

    uint8_t *audioOutBuffer = (uint8_t*)av_malloc( 192000 );

    swr_init( swsCtx );

#if 0
    while( av_read_frame( pFmtCtx, pPkt ) >= 0 ){
        if( pPkt->stream_index != audioStreamIndex ){
            continue;
        }

        if( avcodec_send_packet( pCodecCtx, pPkt ) >=0 ){
            while( avcodec_receive_frame( pCodecCtx,pFrame ) >= 0 ){
                if( av_sample_fmt_is_planar( pCodecCtx->sample_fmt ) ){
                    int len = swr_convert( swsCtx, &audioOutBuffer, 192000 * 2,
                                           ( const uint8_t** )pFrame->data, pFrame->nb_samples );

                    if( len < 0 ){
                        continue;
                    }

                    int dstBufferSize = av_samples_get_buffer_size( 0, outChannels, len, outSampleFmt, 1 );

                    fwrite( audioOutBuffer, 1, dstBufferSize, fd );
                }
            }
        }

        av_packet_unref( pPkt );
    }
#endif

# if 1
    while( av_read_frame( pFmtCtx, pPkt ) >= 0 ){
        if( pPkt->stream_index != audioStreamIndex ){
            continue;
        }

        if( avcodec_send_packet( pCodecCtx, pPkt ) >= 0 ){
            while( avcodec_receive_frame( pCodecCtx, pFrame ) >= 0 ){
                if( av_sample_fmt_is_planar( pCodecCtx->sample_fmt ) ){
                    int perSampleBytes = av_get_bytes_per_sample( pCodecCtx->sample_fmt );

                    for( int sampleIndex = 0; sampleIndex < pFrame->nb_samples; sampleIndex++ ){
                        for( int channelIndex = 0; channelIndex < pCodecCtx->channels; channelIndex++ ){
                            fwrite( reinterpret_cast<char*>( pFrame->data[ channelIndex ] ) + perSampleBytes * sampleIndex, 1, perSampleBytes, fd );
                        }
                    }
                }
            }
        }

        av_packet_unref( pPkt );
    }
#endif

    fclose( fd );
    qDebug() << "done";
}

void CFFmpegAudioDecoder::startPlay()
{
    QFile file( "./ret.pcm" );

    if( !file.open( QIODevice::ReadOnly ) ){
        qDebug() << "open pcm file failed...";
        return;
    }

    QByteArray pcmData = file.readAll();
    qDebug() << "size = " << pcmData.size();
    QAudioFormat audioFmt;
    audioFmt.setSampleRate( 44100 );
    audioFmt.setChannelCount( 2 );
    audioFmt.setSampleSize( 32 );
    audioFmt.setCodec( "audio/pcm" );
    audioFmt.setByteOrder( QAudioFormat::LittleEndian );
    audioFmt.setSampleType( QAudioFormat::Float );

    out = new QAudioOutput( audioFmt );
    m_pAudioPlayer = new CAudioPlayer( pcmData );
    out->start( m_pAudioPlayer );

    qDebug() << "finished...";
}
