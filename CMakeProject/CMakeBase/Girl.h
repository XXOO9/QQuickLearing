#ifndef GIRL_H
#define GIRL_H

#include <iostream>
#include "./Boy.h"

using namespace std;
class Boy;

class Girl
{
public:
    Girl();
    ~Girl();

    void setBoy( shared_ptr<Boy> boy );

    shared_ptr<Boy> m_boy;
};

#endif // GIRL_H
