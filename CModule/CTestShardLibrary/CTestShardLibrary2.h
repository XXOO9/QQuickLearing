#ifndef CTESTSHARDLIBRARY2_H
#define CTESTSHARDLIBRARY2_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QDebug>
#include "ctestshardlibrary_global.h"

class CTESTSHARDLIBRARYSHARED_EXPORT CTestShardLibrary2 : public QObject
{
    Q_OBJECT
public:

    QString display();
    static CTestShardLibrary2* getInstance();
private:
    explicit CTestShardLibrary2(QObject *parent = nullptr);

private:
    static QMutex m_mutex;
    static CTestShardLibrary2* m_pTest2;

};

#endif // CTESTSHARDLIBRARY2_H
