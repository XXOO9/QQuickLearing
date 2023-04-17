#ifndef GIRL_H
#define GIRL_H

#include <iostream>
#include "./Boy.h"
#include "SharedPointerGlobal.h"

using namespace std;
class Boy;

class DLLEXPORT Girl
{
public:
    Girl();
    ~Girl();

    void setBoy( weak_ptr<Boy> boy );

    weak_ptr<Boy> m_boy;
};

#endif // GIRL_H
