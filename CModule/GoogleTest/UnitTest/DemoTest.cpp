#include "tst_testcase.h"
//#include "../QtClass/QtClassTest.h"
#include "QtClassTest.h"

TEST( QtClass, testt )
{
    QtClassTest *test = new QtClassTest();
    EXPECT_EQ( "Qt", test->display() );

//    test->emitSig();
}
