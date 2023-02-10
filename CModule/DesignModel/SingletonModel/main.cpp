#include <QCoreApplication>
#include "CSingletonClass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CSingletonClass *ptr = CSingletonClass::getInstance();

    ptr->getAddr();

//    return a.exec();
    return 0;
}
