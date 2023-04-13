#include "CTester.h"

CTester::CTester()
{
    cout << "CTester Constructor..." << endl;
    compileSystemInfo();

    CTestSharedLib::m_val = 20;
    cout << "change val to " << CTestSharedLib::m_val << endl;
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
