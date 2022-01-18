#ifndef CFUNCTION_H
#define CFUNCTION_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>

class CFunction : public QObject
{
    Q_OBJECT
public:
    explicit CFunction(QObject *parent = nullptr);
    ~CFunction();

    void init();

signals:
    void sigFuncDone();

public slots:
    void display();

    void stopDisplay();

private:
    bool       m_isRunning{ true };
    QMutex     m_mutex;
};

#endif // CFUNCTION_H
