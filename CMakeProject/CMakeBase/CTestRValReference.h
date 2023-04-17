#ifndef CTESTRVALREFERENCE_H
#define CTESTRVALREFERENCE_H

/*
 * 截止到2023.04.17 得出结论，移动构造只能移动指针对象不能移动普通成员变量
*/

#include "Common.h"

class CTestRValReference
{
public:
    CTestRValReference();
    CTestRValReference( CTestRValReference &&other );
    ~CTestRValReference();


    //完美转发
    void testReference( int &val  );
    void testReference( int &&val );
    void pass(int &&val );
    void pass( int &val );
    void showValAddr();
    int *pVal() const;

    void testStandardMove();

    int *m_pVal = nullptr;
    int  m_norVal = 20;
};

#endif // CTESTRVALREFERENCE_H
