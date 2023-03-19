#ifndef STRINGALGORITHM_H
#define STRINGALGORITHM_H
#include <QDebug>

class StringAlgorithm
{
public:
    StringAlgorithm();

    void findFirstSunstr( const char *srcStr, const char *tarStr );

    void aboutSizeof();

    void strReplace( const char *tarStr, const char *srcStr );
};

#endif // STRINGALGORITHM_H
