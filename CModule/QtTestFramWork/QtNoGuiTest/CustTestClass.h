#ifndef CUSTTESTCLASS_H
#define CUSTTESTCLASS_H

#include <QObject>
#include <QDebug>
#include <QtTest>
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>


class CustTestClass : public QObject
{
    Q_OBJECT
public:
    explicit CustTestClass(QObject *parent = nullptr);

    void testFunc();

signals:
    void sigTest();

private slots:
    void display();

    void onSig();
};

#endif // CUSTTESTCLASS_H
