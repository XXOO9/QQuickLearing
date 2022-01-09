#include "tst_casename.h"
#include "../PlainCppTestDemo/NoClassTest.h"
#include "../PlainCppTestDemo/CClassTest.h"
#include "../QtClass/QtClassTest.h"

TEST(NoClass, add)
{
    EXPECT_EQ( 2, add( 1, 1) );
}

TEST(Class, display)
{
    CClassTest test;
    EXPECT_EQ( "WDNMD", test.display() );
}

TEST( QtClass, display)
{
    QtClassTest test;
    EXPECT_EQ( "WDNMD_Qt", test.display() );
}

TEST( QtClass, async)
{
    QtClassTest test;
    test.startTimer();
    EXPECT_EQ( true, test.isFinished() );
}
