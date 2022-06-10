#ifndef CTESTQUITTHREAD_H
#define CTESTQUITTHREAD_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <QMutexLocker>
#include <QMutex>

class ThreadTimer : public QObject
{
    Q_OBJECT
public:
    explicit ThreadTimer(QObject *parent = nullptr);

private:
    QThread *m_pThread = nullptr;
};

#endif // CTESTQUITTHREAD_H
