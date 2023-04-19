#include "CThread.h"

CThread::CThread()
{
    cout << "constructos CThread..." << endl;
    initThread();
}

CThread::~CThread()
{
    cout << "distory CThread..." << endl;
}

void CThread::testThreadA()
{
    m_val = 1;
    cout << "call test thread A" << endl;
}

void CThread::testThreadB()
{
    m_val = 2;
    cout << "call test thread B" << endl;
}

void CThread::testThreadC()
{
    m_val = 3;
    cout << "call test thread C" << endl;
}

void CThread::testCount()
{
    std::function<void (void)> func = [this](){
        int i = 10000;
        while( i-- ){
            m_val++;
        }
    };
}

void CThread::initThread()
{
    auto funcA = [this](){ testThreadA(); };
    shared_ptr<thread> a = make_shared< thread >( funcA );

    auto funcB = [this](){ testThreadB(); };
    shared_ptr<thread> b = make_shared< thread >( funcB );

    auto funcC = [this](){ testThreadC(); };
    shared_ptr<thread> c = make_shared< thread >( funcC );


    a->join();
    b->join();
    c->join();
}
