#include "tst_testcase.h"
#include <QCoreApplication>
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    QCoreApplication app( argc, argv );
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    if( ret < 0 ){
        return ret;
    }
    return app.exec();
}
