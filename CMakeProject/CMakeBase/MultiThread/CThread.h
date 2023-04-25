#ifndef CTHREAD_H
#define CTHREAD_H

#include "MultiThread_Global.h"

#include <iostream>
#include <memory>
#include <iomanip>
#include <functional>
#include <thread>
#include <mutex>
#include <chrono>


using namespace std;

class SHARED_EXPORT CThread
{
public:
    CThread();
    ~CThread();

    void testMutex();

    void testGuradMutex();

    void testCondition();

    void testConditionVariable();
};

#endif // CTHREAD_H
