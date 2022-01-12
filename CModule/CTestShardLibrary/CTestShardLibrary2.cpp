#include "CTestShardLibrary2.h"

QMutex CTestShardLibrary2::m_mutex;
CTestShardLibrary2* CTestShardLibrary2::m_pTest2 = nullptr;

CTestShardLibrary2::CTestShardLibrary2(QObject *parent) : QObject(parent)
{
    qDebug() << "Create singeton";
}

QString CTestShardLibrary2::display()
{
    return "this is test 2, hahaha ...";
}

CTestShardLibrary2 *CTestShardLibrary2::getInstance()
{
    m_mutex.lock();
    if( nullptr == m_pTest2 ){
        m_pTest2 = new CTestShardLibrary2();
    }
    m_mutex.unlock();
    return m_pTest2;
}


