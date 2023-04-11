#pragma once
#include <iostream>

using namespace std;

#if defined(WIN32)
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT 
#endif

class DLLEXPORT CTestSharedLib
{
public:
    CTestSharedLib();
};
