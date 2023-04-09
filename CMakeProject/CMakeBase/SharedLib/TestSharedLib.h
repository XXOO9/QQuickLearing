#pragma once
#include <iostream>

using namespace std;
#define DLLEXPORT __declspec(dllexport)

class DLLEXPORT CTestSharedLib
{
public:
    CTestSharedLib();
};
