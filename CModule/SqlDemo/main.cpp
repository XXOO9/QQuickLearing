#include <QCoreApplication>
#include <CSqlLite.h>
#include "./liteSql/CTestLiteSql.h"
#include "./MySql/CTestMySql.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CTestMySql::init();

    return a.exec();
}
