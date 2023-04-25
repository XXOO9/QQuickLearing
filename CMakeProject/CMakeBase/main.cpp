#include<iostream>
#include <thread>
#include "CTester.h"
#include "CLambdaTest.h"
#include "Common.h"
#include <memory>


int main()
{
    CThread a;
    a.testConditionVariable();
    cout << "main thread ID = " << std::this_thread::get_id() << endl;
    return 0;
}
