#ifndef CTESTCLASS_H
#define CTESTCLASS_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class CTestClass
{
public:
    CTestClass();

    void display();

private:
    QTimer  *m_pTimer = nullptr;
};

#endif // CTESTCLASS_H
