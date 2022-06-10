#ifndef THREADPRINT_H
#define THREADPRINT_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>


/*
 * 1.线程的开始和停止都应该在线程外部控制
 * 2. 线程的finish信号要在线程开启之前（在旧线程中绑定）
 * 3.如果线程对象（QThread）是堆分配的，则连接finish信号避免内存泄漏, 如果是栈分配的， 则在退出时，调用wait（）防止未析构完时栈上的内存就被释放了
*/

class ThreadPrint : public QObject
{
    Q_OBJECT
public:
    explicit ThreadPrint(QObject *parent = nullptr);
    virtual ~ThreadPrint();
    void startPrint();

    void stopThread();

    bool stopTimer();


    QThread *printThread() const;

signals:
    void insideSigStartPrint();

    void insideSigStartCount();

    //在线程中开启定时器
    void insideStartTimer();

    //测试在开启线程后，发送绑定信号槽的信息
    void insideSigInitConnection();

    void insideSigKillThread();

private slots:
    void onStartPrint();
    void onStartCount();
    void onConnection();
    void onThreadFinished();
    void onStartTimer();
    void onKillThread();


    void onTimerTimeout();
private:
    void init();
    void initConnection();
private:
    QThread *m_printThread;
    QMutex  m_mutex;
    bool    m_printFlag = false;
    QTimer  *m_timer = nullptr;
};

#endif // THREADPRINT_H
