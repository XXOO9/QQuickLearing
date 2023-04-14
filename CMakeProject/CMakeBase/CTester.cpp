#include "CTester.h"

CTester::CTester()
{
    cout << "CTester Constructor..." << endl;
    compileSystemInfo();
}

CTester::~CTester()
{

}

void CTester::compileSystemInfo()
{
#if defined( WIN32 )
    cout << "this is windows platform..." << endl;
    cout << _MSC_VER << endl;
#elif defined(linux)
    cout << "this is linux platform..." << endl;
#else
    cout << "this is unKnown platform..." << endl;
#endif
}

void CTester::test()
{
    shared_ptr<CTestSharedLib>  p( new CTestSharedLib );
    weak_ptr<CTestSharedLib> first = p;
    cout << first.expired() << endl;

    if( !first.expired() ){
        auto tmpPtr = first.lock();
        cout << "use cnt = " << tmpPtr.use_count() << endl;
    }
}

shared_ptr<CTestSharedLib> CTester::getShared()
{
    shared_ptr<CTestSharedLib> p;
    cout << "use cnt = " << p.use_count() << endl;
//    CTestSharedLib *p = new CTestSharedLib();
    shared_ptr<CTestSharedLib> ret( p );
    cout << "create addr = " << ret << endl;
    return ret;
}
