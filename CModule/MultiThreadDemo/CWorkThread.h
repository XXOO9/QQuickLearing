#ifndef CWORKTHREAD_H
#define CWORKTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMetaType>
#include "CFunction.h"


class CWorkThread : public QObject
{
    Q_OBJECT
public:
    explicit CWorkThread(QObject *parent = nullptr);
    ~CWorkThread();

    void init();

    void initConnection();

    void startDisplay();

    void stopDisplay();



signals:
    void sigStartDisplay( QVariant data );

public slots:

public:
    CFunction   m_func;
    QThread     *m_pWorkThread;
};

#endif // CWORKTHREAD_H
