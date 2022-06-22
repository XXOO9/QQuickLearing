#ifndef CTESTA_H
#define CTESTA_H

#include <QDebug>
#include <QString>
#include <QObject>
#include <QImage>
#include <QSize>
#include <QPainter>
#include <QPen>
#include <QFont>
#include <QMatrix>
#include <stdlib.h>

class CTestA
{
public:
    CTestA();

    QImage createImg();

    void getArray( QImage &img );

    void Vector2Array(QVector<int> &vecPos);

    void test();

    void testFunc();

    void testFunc2();

    void display( char (*ptr)[16] );

    void display_version2(unsigned short *ptr );

//    void displayLine(QVector<QStringList> vec);
};

#endif // CTESTA_H
