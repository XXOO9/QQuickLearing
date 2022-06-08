#include <QTest>
#include "TestA.h"
#include "TestB.h"

int main( int argc, char *argv[] )
{
    TestB a;
    int ret = QTest::qExec( &a, argc, argv );

    qDebug() << "ret=  = " << ret;

    return 0;
}
