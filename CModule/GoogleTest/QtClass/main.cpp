#include <QCoreApplication>
#include "QtClassTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QtClassTest test;

    return a.exec();
}
