#include "CFastSort.h"
#include <QRandomGenerator>

CFastSort::CFastSort()
{
    QVector<int> vecNumbers;

    int cnt = 13;
    while( cnt-- ){
       int tmp = QRandomGenerator::global()->bounded( 0, 100 );
       vecNumbers << tmp;
    }
    fastSort( vecNumbers );
}

void CFastSort::fastSort( QVector<int> &src )
{
    qDebug() << src;

    // 一般以第一个数作为基准数
    int baseNumber = src.first();


    //先从最右边开始移动
    int leftStartPos = 0;
    int rightStartPos = src.size() - 1;


    while( leftStartPos < rightStartPos ){

        //找到右边大于baseNumber的数字
        while( ( src[ rightStartPos ] >= baseNumber ) && ( rightStartPos > leftStartPos ) ){
            rightStartPos--;
        }

        while( ( src[ leftStartPos ] <= baseNumber ) && ( leftStartPos < rightStartPos ) ){
            leftStartPos++;
        }

        qDebug() << "left = " << src[ leftStartPos ] << leftStartPos;
        qDebug() << "right = " << src[ rightStartPos ] << rightStartPos;

        int tmp = src[ leftStartPos ];
        src[ leftStartPos ] = src[ rightStartPos ];
        src[ rightStartPos ] = tmp;
        qDebug() << src;
    }

    int tmp = src[ 0 ];

    src[ 0 ] = src[ leftStartPos ];
    src[ leftStartPos ] = tmp;

    qDebug() << src;
}








