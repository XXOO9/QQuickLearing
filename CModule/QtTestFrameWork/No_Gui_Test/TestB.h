#ifndef TESTB_H
#define TESTB_H

#include <QObject>
#include <QSignalSpy>
#include <QDebug>
#include <QTest>
#include "SignalTest.h"

class TestB : public QObject
{
    Q_OBJECT
public:
    explicit TestB(QObject *parent = nullptr);

private slots:
    void init();
    void cleanup();
    void case_testSignal();
    void case_test2();
};

#endif // TESTB_H
