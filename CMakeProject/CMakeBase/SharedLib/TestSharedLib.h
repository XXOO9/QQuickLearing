#pragma once
#include <iostream>

using namespace std;

#if defined( LIBRYARYEXPORT )
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT CTestSharedLib
{
public:
    explicit CTestSharedLib();
    ~CTestSharedLib();
    static int m_val;
};
