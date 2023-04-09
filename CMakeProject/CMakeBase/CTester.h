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
};

#endif // CTESTER_H
