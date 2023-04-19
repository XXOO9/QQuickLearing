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
    CThread b;
    thread a( [ & ](){
        cout << "threadTest thread ID = " << std::this_thread::get_id() << endl;
        cout << "WDNMD" << endl;

    } );

//    a.join();
    cout << "val = " << b.m_val << endl;
//    a.detach();

    return a;
}

int main()
{
    cout << "main thread ID = " << std::this_thread::get_id() << endl;
    thread th = threadTest();

    if( th.joinable() ){
        cout << "join able..." << endl;
    }

    std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
    cout << "111" << endl;
    return 0;
}
