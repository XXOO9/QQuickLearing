#include "StringAlgorithm.h"
#include <string.h>
StringAlgorithm::StringAlgorithm()
{
    findFirstSunstr( "WDLSOLN:LJDSGNGN:KNNMD", ":LJDSGNGN:" );
    aboutSizeof();
}

void StringAlgorithm::findFirstSunstr(const char *srcStr, const char *tarStr)
{
    char firstChar = *tarStr;
    char curChar   = *srcStr;

    size_t len = strlen( tarStr);

    size_t step = 0;
    size_t index = 0;

    while( *srcStr != '\0' ){

        const char *tmpSrc = srcStr;
        const char *tmpTar = tarStr;

        firstChar = *tmpTar;
        curChar   = *srcStr;

        while( curChar == firstChar ){

            tmpSrc++;
            tmpTar++;

            firstChar = *tmpTar;
            curChar   = *tmpSrc;

            step++;

            if( step == len ){
                qDebug() << "index = " << index;
                break;
            }
        }
        index++;
        srcStr++;
    }

    if( *srcStr == '\0' ){
        qDebug() << "no index";
    }
}

void StringAlgorithm::aboutSizeof()
{
    char str[ 100 ] = { 0 };
    char *pStr = str;
    qDebug() << "size of = " << sizeof ( pStr );
}

void StringAlgorithm::strReplace(const char *tarStr, const char *srcStr)
{
    char src[20] = { 0 };

    while( *src != '\0' ){
        if( *src == *tarStr ){

        }
    }
}
