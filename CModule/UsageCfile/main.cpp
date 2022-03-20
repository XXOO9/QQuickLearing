#include <QCoreApplication>
#include "calculate.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int ret;
    ret = add( 2, 3);
    qDebug() << "ret = " << ret;

    display();
    return a.exec();
}
