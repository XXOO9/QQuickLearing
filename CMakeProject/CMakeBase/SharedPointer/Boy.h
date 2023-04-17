#ifndef BOY_H
#define BOY_H

#include <iostream>
#include "SharedPointerGlobal.h"
#include "./Girl.h"

class Girl;

using namespace std;

class DLLEXPORT Boy
{
public:
    Boy();
    Boy( Boy &&other );
    ~Boy();

    Boy& operator =( Boy &&other );
    void setHirl( weak_ptr<Girl> girl);

    weak_ptr<Girl>    m_girl;
};

#endif // BOY_H
