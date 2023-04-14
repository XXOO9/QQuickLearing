#include "TestSharedLib.h"

CTestSharedLib::CTestSharedLib()
{
#ifdef LIBRYARYEXPORT
    cout << "check define LIBRYARYEXPORT " << endl;
#endif
    cout << "call Shared constructor addr = " << this << endl;
}

CTestSharedLib::~CTestSharedLib()
{
    cout << "call Shared distructor addr = " << this << endl;
}

int CTestSharedLib::m_val = 10;
