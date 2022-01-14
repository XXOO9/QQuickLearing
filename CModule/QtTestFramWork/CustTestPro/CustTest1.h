#ifndef CUSTTEST1_H
#define CUSTTEST1_H

#include <QObject>
#include <QDebug>

class CustTest1 : public QObject
{
    Q_OBJECT
public:
    explicit CustTest1(QObject *parent = nullptr);

private slots:
    void onTest1();
};

#endif // CUSTTEST1_H
