#include "CLambdaTest.h"
#include <functional>

CLambdaTest::CLambdaTest()
{
    test();
}

void CLambdaTest::test()
{
    int val = 1;

    std::function< int ( int ) > func = [=]( int offset ) mutable -> int{ return val + offset; };
    auto bindFunc = std::bind( func, 2 );

    int ret = bindFunc();

    std::function< void(int) > show = std::bind( &CLambdaTest::displayParameter, this, placeholders::_1 );
    show( 2 );

}

void CLambdaTest::display()
{
    cout << "this is display..." << endl;
}

void CLambdaTest::displayParameter(int val)
{
    cout << "val = " << val << endl;
}
