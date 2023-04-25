#include "CThread.h"


CThread::CThread()
{
    cout << "constructos CThread..." << endl;
    //    initThread();
}

CThread::~CThread()
{
    cout << "distory CThread..." << endl;
}

void CThread::testMutex()
{
    std::mutex mutex;
    int val = 0;

    auto funA = [ & ](){
        while( true ){
            mutex.lock();
            cout << "change val by funA = " << ++val << " addr = " << &val << endl;
            mutex.unlock();
            std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
        }
    };

    auto funB = [ & ](){
        while( true ){
            mutex.lock();
            val *= 2;
            cout << "change val by funB = " << val << " addr = " << &val << endl;
            mutex.unlock();
            std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
        }
    };

    shared_ptr< thread > tha = make_shared< thread >( funA );
    shared_ptr< thread > thb = make_shared< thread >( funB );

    tha->join();
    thb->join();

}

void CThread::testGuradMutex()
{
    std::mutex mutex;
    std::lock_guard< std::mutex > guardLock( mutex );
}

void CThread::testCondition()
{

}

void CThread::testConditionVariable()
{
    std::mutex mutex;
    std::condition_variable cv;
    bool ready = false;

    auto print = [ & ]( const int id ){
        std::unique_lock< std::mutex > lock( mutex );
//        while( !ready ){
//            cout << "coming thread = " << id << endl;
//            cv.wait( lock );
//            cout << "after wait= " << id << endl;
//        }


        cout << "coming thread = " << id << endl;
        cv.wait( lock );
        cout << "thread display id = " << id << endl;
    };

    auto go = [ & ](){
        std::unique_lock< std::mutex > lock( mutex );
//        cv.notify_all();
        cv.notify_one();
    };

    thread thArray[ 10 ];

    for( int index = 0; index < 10; index++ ){
        thArray[ index ] = thread( print, index );
    }

    cout << "threads ready race..." << endl;

    std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

    go();

    for( auto &ele : thArray ){
        ele.join();
    }
}
