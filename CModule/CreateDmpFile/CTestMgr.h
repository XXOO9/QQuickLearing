#ifndef CTESTMGR_H
#define CTESTMGR_H

#include <QObject>
#include "CTestClass.h"

class CTestMgr : public QObject
{
    Q_OBJECT
public:
    explicit CTestMgr(QObject *parent = nullptr);
    Q_INVOKABLE void testFunc();
};

#endif // CTESTMGR_H
