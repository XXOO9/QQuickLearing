#include "Girl.h"

Girl::Girl()
{
    cout << "create a girl!" << endl;
}

Girl::~Girl()
{
    cout << "kill a girl..." << endl;
}

void Girl::setBoy(weak_ptr<Boy> boy)
{
    m_boy = boy;
}
