#include "CTester.h"

CTester::CTester()
{
    cout << "CTester Constructor..." << endl;
    compileSystemInfo();
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
