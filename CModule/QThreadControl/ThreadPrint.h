#ifndef THREADPRINT_H
#define THREADPRINT_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>

class ThreadPrint : public QObject
{
    Q_OBJECT
public:
    explicit ThreadPrint(QObject *parent = nullptr);
    virtual ~ThreadPrint();
    void startPrint();

    void stopThread();

    void killThread();

    bool stopTimer();


signals:
    void insideSigStartPrint();

    void insideSigStartCount();

    //在线程中开启定时器
    void insideStartTimer();

    //测试在开启线程后，发送绑定信号槽的信息
    void insideSigInitConnection();

private slots:
    void onStartPrint();
    void onStartCount();
    void onConnection();
    void onThreadFinished();
    void onStartTimer();


    void onTimerTimeout();
private:
    void init();
    void initConnection();
private:
    QThread m_printThread;
    QMutex  m_mutex;
    bool    m_printFlag = false;
    QTimer  m_timer;
};

#endif // THREADPRINT_H
