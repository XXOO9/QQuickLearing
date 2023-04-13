#include "TestSharedLib.h"

CTestSharedLib::CTestSharedLib()
{
    #ifdef LIBRYARYEXPORT
    cout << "check define LIBRYARYEXPORT " << endl;
    #endif
    
    cout << "Constructor Shared lib..." << endl;
    m_val = 5;
    cout << "val = " << m_val << endl;
}

int CTestSharedLib::m_val = 10;