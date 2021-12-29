#include "SyncUserInfoTest.h"

SyncUserInfoTest::SyncUserInfoTest(QString timeStamp, QObject *parent) : QObject(parent), m_syncClassInfo( timeStamp )
{
    m_syncClassInfo.httpRequest();
}

SyncUserInfoTest::~SyncUserInfoTest()
{

}
