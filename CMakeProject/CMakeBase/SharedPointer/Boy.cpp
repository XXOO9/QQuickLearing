#include "Boy.h"

Boy::Boy()
{
    cout << "create a boy!" << endl;
}

Boy::Boy(Boy &&other)
{
    cout << "call boy move constructor..." << endl;
}

Boy::~Boy()
{
    cout << "kill a boy..." << endl;
}

Boy &Boy::operator =(Boy &&other)
{
    cout << "call boy move equal..." << endl;
    return other;
}

void Boy::setHirl(weak_ptr<Girl> girl)
{
    m_girl = girl;
}
