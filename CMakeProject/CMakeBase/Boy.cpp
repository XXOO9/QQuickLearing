#include "Boy.h"

Boy::Boy()
{
    cout << "create a boy!" << endl;
}

Boy::~Boy()
{
    cout << "kill a boy..." << endl;
}

void Boy::setHirl(shared_ptr<Girl> girl)
{
    m_girl = girl;
}
