#include "CTestRValReference.h"

CTestRValReference::CTestRValReference()
{
    cout << "call CTestRValReference default constructor..." << endl;

    m_pVal = new int( 10 );
}

CTestRValReference::CTestRValReference( CTestRValReference &&other )
{
    cout << "call CTestRValReference move constructor..." << endl;
    m_pVal = other.m_pVal;
    other.m_pVal = nullptr;
}

CTestRValReference::~CTestRValReference()
{

}

void CTestRValReference::testReference(int &val)
{
    cout << "调用左值参数" << endl;
}

void CTestRValReference::testReference(int &&val)
{
    cout << "调用右值参数" << endl;
}

void CTestRValReference::pass( int &&val )
{
    auto ret = std::forward<int>( val );
    testReference( ret );
}

void CTestRValReference::pass(int &val)
{
    testReference( val );
}

void CTestRValReference::showValAddr()
{
    cout << "val addr = " << m_pVal << endl;
    cout << "normal addr = " << &m_norVal << endl;
}

int *CTestRValReference::pVal() const
{
    return m_pVal;
}

void CTestRValReference::testStandardMove()
{
    string str = "WDNMD";
    vector<string> vec;

    vec.push_back( move( str ) );

    cout << "str = " << str << endl;

    for( auto ele : vec ){
        cout << "ele = " << ele << endl;
    }
}
