#include "CMainWidget.h"
#include <QApplication>
#include <omp.h>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWidget w;
    w.show();

    return a.exec();
}
