#include "CTestMgr.h"

CTestMgr::CTestMgr(QObject *parent) : QObject(parent)
{

}

void CTestMgr::testFunc()
{
    CTestClass      *ptr = nullptr;
    if( nullptr == ptr ){
        qDebug() << "error...";
    }
    ptr->display();
}
