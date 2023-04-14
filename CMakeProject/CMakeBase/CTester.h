#ifndef CTESTER_H
#define CTESTER_H

#include <iostream>
#include "./StaticLib/TestStaticLib.h"
#include "./SharedLib/TestSharedLib.h"

using namespace std;

class CTester
{
public:
    CTester();
    CTestStaticLib a;
    CTestSharedLib b;

private:
    void compileSystemInfo();


    void test();
    shared_ptr<CTestSharedLib> getShared();
};

#endif // CTESTER_H
