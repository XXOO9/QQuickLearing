#ifndef CUPDSTATION_H
#define CUPDSTATION_H

#include <QObject>
#include <QUdpSocket>
#include <QDebug>

class CUPDStation : public QObject
{
    Q_OBJECT
public:
    explicit CUPDStation(QObject *parent = nullptr);

    Q_INVOKABLE void send();

public slots:
    void onNewMessage();
private:
    void init();
private:
    QUdpSocket  *m_pUdpSocket = nullptr;
};

#endif // CUPDSTATION_H
