#include <QCoreApplication>
#include <CSqlLite.h>
#include "./liteSql/CTestLiteSql.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CTestLiteSql sql;

    return a.exec();
}
