#ifndef QLOG_H
#define QLOG_H

#include <QLog.h>
#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QFile>
#include <QDateTime>
#include <QDebug>

class QLog
{
public:
    QLog();

private:
    void init();
    void myMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private:
    QMutex  m_mutex;
};

#endif // QLOG_H
