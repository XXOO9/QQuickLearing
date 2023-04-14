#ifndef BOY_H
#define BOY_H

#include <iostream>
#include "./Girl.h"

class Girl;

using namespace std;

class Boy
{
public:
    Boy();
    ~Boy();

    void setHirl( shared_ptr<Girl> girl);

    shared_ptr<Girl>    m_girl;
};

#endif // BOY_H
