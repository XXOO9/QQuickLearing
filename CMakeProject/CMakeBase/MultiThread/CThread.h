#ifndef CTHREAD_H
#define CTHREAD_H

#include "MultiThread_Global.h"

#include <iostream>
#include <memory>
#include <functional>
#include <thread>

using namespace std;

class SHARED_EXPORT CThread
{
public:
    CThread();
    ~CThread();

    void testThreadA();

    void testThreadB();

    void testThreadC();

private:
    void initThread();

private:
    shared_ptr<thread>  m_tha;
    shared_ptr<thread>  m_thb;
    shared_ptr<thread>  m_thc;
};

#endif // CTHREAD_H
