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
    void sigTestArgument( QString content );

    void sigTestNoArgument();

private slots:
    void sendSignalWithArgument();

    void sendSignalNoArgument();

    void onSigWithArgument( QString content );

    void onSigNoArgument();

    void someMacro();

private slots:

    void testQString_data();

    void testQString();


};

#endif // CUSTTESTCLASS_H
