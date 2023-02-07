#include "CAudioPlayer.h"

CAudioPlayer::CAudioPlayer(const QByteArray srcPcm) : m_pcmData( srcPcm )
{
    this->open( QIODevice::ReadOnly );
    m_writtenLen = 0;
}

CAudioPlayer::~CAudioPlayer()
{
    this->close();
}

qint64 CAudioPlayer::readData(char *data, qint64 maxlen)
{
    //如果已经写入的字节数大于等于的总共的字节数，说明已经播放完了，直接返回
    if( m_writtenLen >= m_pcmData.size() ){
        return 0;
    }

    //计算还未播放完的字节数， 如果已经播放完了的字节数加上maxLen > 总共的字节数，说明：只用播放剩下的字节数
    int len = ( m_writtenLen + maxlen ) > m_pcmData.size() ? ( m_pcmData.size() - m_writtenLen ) : maxlen;
    memcpy( data, m_pcmData.mid( m_writtenLen, m_writtenLen + len ).data(), len );
    m_writtenLen += len;
    return len;
}

qint64 CAudioPlayer::writeData(const char *data, qint64 len)
{
    return len;
}

void CAudioPlayer::startAudioPlay()
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

    QAudioOutput *out = new QAudioOutput( audioFmt, this );
    CAudioPlayer *audioPlayer = new CAudioPlayer( pcmData );
    out->start( audioPlayer );

    qDebug() << "finished...";
}
