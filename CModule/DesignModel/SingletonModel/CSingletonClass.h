#ifndef CSINGLETONCLASS_H
#define CSINGLETONCLASS_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QMutexLocker>
#include <QMutex>
/*
 * 详细注释见cpp末尾
*/

class CSingletonClass
{
public:
    static CSingletonClass *getInstance();
    void getAddr() const;
    ~CSingletonClass();

private:
    CSingletonClass();


    static CSingletonClass  *m_pSingleton;
    static QMutex            m_mutex;
};

#endif // CSINGLETONCLASS_H
