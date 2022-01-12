#include "CTestShardLibrary.h"

CTestShardLibrary::CTestShardLibrary(QObject *parent) : QObject(parent)
{

}

QString CTestShardLibrary::display()
{
    return "this is display...";
}
