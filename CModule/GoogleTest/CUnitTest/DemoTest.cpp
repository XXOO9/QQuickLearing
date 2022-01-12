#include "tst_casename.h"
#include "../PlainCppTestDemo/NoClassTest.h"
#include "../QtClass/QtClassTest.h"

#include <QEventLoop>

TEST(NoClass, add)
{
    EXPECT_EQ( 2, add( 1, 1) );
}

TEST( QtClass, async)
{
    QtClassTest test;
    test.startTimer();
    QEventLoop loop;
    QObject::connect( &test, &QtClassTest::sigTriggered, &loop, &QEventLoop::quit );
    loop.exec();
    EXPECT_EQ( false, test.isFinished() );
}
