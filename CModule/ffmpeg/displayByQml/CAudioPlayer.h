#ifndef CAUDIOPLAYER_H
#define CAUDIOPLAYER_H

#include <QObject>
#include <QIODevice>
#include <QDebug>
#include <QFile>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QEventLoop>

class CAudioPlayer : public QIODevice
{
public:
    CAudioPlayer(const QByteArray srcPcm );
    virtual ~CAudioPlayer() override;


    virtual qint64 readData(char *data, qint64 maxlen) override;
    virtual qint64 writeData(const char *data, qint64 len) override;


    void startAudioPlay();
private:
    QByteArray  m_pcmData;
    int         m_writtenLen = 0;
};

#endif // CAUDIOPLAYER_H
