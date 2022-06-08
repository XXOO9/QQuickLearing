#include "CTestClass.h"

CTestClass::CTestClass()
{

}

void CTestClass::display()
{
    qDebug() << "this is display...";
    m_pTimer->start();
}
