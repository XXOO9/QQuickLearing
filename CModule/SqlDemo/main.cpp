#include <QCoreApplication>
#include <CSqlLite.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CSqlLite sql;

    return a.exec();
}
