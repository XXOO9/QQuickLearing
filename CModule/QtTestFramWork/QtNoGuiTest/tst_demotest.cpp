#include <QtTest>
#include <QCoreApplication>
#include <QDebug>
#include "CustTestClass.h"


int main( int argc, char **argv )
{
    QCoreApplication app( argc, argv );
    CustTestClass test;
    QTest::qExec( &test, argc, argv );
    return app.exec();
}
