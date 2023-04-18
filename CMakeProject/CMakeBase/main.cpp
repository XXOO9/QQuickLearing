#include<iostream>
#include <thread>
#include "CTester.h"
#include "CLambdaTest.h"
#include "Common.h"
#include <memory>

void test()
{
    CThread a;
}

thread threadTest()
{

    thread a( [](){
        cout << "threadTest thread ID = " << std::this_thread::get_id() << endl;
        cout << "WDNMD" << endl;
        CThread b;
    } );

//    a.join();
    cout << "2222" << endl;
//    a.detach();

    return a;
}

int main()
{
    cout << "main thread ID = " << std::this_thread::get_id() << endl;
    thread a = threadTest();

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );

    if( a.joinable() ){
        a.join();
    }

    cout << "111" << endl;
    return 0;
}
