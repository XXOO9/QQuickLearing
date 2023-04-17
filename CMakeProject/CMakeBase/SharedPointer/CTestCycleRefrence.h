#ifndef CTESTCYCLEREFRENCE_H
#define CTESTCYCLEREFRENCE_H

/*
 * 这个类主要测试C++共享指针的一些用法和一些坑，比如循环引用之类的
 *
*/

#include "Boy.h"
#include "Girl.h"
#include "SharedPointerGlobal.h"

class DLLEXPORT CTestCycleRefrence
{
public:
    CTestCycleRefrence();
    ~CTestCycleRefrence();
private:
    void init();
private:
    shared_ptr<Boy>  m_boy;
    shared_ptr<Girl> m_girl;
};

#endif // CTESTCYCLEREFRENCE_H
