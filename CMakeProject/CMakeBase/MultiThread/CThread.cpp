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
    cout << "call test thread A" << endl;
}

void CThread::testThreadB()
{
    cout << "call test thread B" << endl;
}

void CThread::testThreadC()
{
    cout << "call test thread C" << endl;
}

void CThread::initThread()
{
//    auto funcA = [this](){ testThreadA(); };
//    shared_ptr<thread> a = make_shared< thread >( funcA );
//    a->join();

//    auto funcB = [this](){ testThreadB(); };
//    shared_ptr<thread> b = make_shared< thread >( funcB );
//    b->join();

//    auto funcC = [this](){ testThreadC(); };
//    shared_ptr<thread> c = make_shared< thread >( funcC );
//    c->join();

}
