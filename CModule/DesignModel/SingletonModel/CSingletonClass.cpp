#include "CSingletonClass.h"

CSingletonClass::CSingletonClass()
{

}

CSingletonClass *CSingletonClass::getInstance()
{
    //懒汉式不是线程安全的，需要加锁同步
    QMutexLocker autoLocker( &m_mutex );
    if( nullptr == m_pSingleton ){
        m_pSingleton = new CSingletonClass();
    }

    return m_pSingleton;
}

void CSingletonClass::getAddr() const
{
    qDebug() << "addr = " << m_pSingleton;
}

CSingletonClass::~CSingletonClass()
{
    qDebug() << "singleton destoried...";
}

/*
 * 热知识： 类的静态成员变量只属于类，而不属于类对象,类的静态成员变量在定义的时候就初始化了
*/

//2023.02.09， 根据目前的理解，定义这里如果new出来了那就是饿汉式，如果定义成nullptr，那就是懒汉式
CSingletonClass*    CSingletonClass::m_pSingleton = nullptr;
QMutex              CSingletonClass::m_mutex;

//2023.02.09，饿汉模式之所以线程安全是因为程序在最开始的时候，静态 m_pSingleton 就已经分配了内存完成了创建
//CSingletonClass*    CSingletonClass::m_pSingleton = new CSingletonClass();
