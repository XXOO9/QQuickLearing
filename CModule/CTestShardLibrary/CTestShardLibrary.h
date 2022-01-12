#ifndef CTESTSHARDLIBRARY_H
#define CTESTSHARDLIBRARY_H

#include <QObject>
#include <QString>
#include "ctestshardlibrary_global.h"

class CTESTSHARDLIBRARYSHARED_EXPORT CTestShardLibrary : public QObject
{
    Q_OBJECT
public:
    explicit CTestShardLibrary(QObject *parent = nullptr);
    QString display();

signals:

public slots:
};

#endif // CTESTSHARDLIBRARY_H
