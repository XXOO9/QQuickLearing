#include "CFastSort.h"
#include <QRandomGenerator>

CFastSort::CFastSort()
{
    guluguluSort();
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

void CFastSort::guluguluSort()
{
    QVector< int > src = generate( 10 );

    qDebug() << src;
    for( int index = 0; index < src.size(); index++ ){
        for( int tmpIndex = index; tmpIndex < src.size(); tmpIndex++ ){
            if( src[ index ] < src[ tmpIndex ] ){
                int tmp = src[ index ];
                src[ index ] = src[ tmpIndex ];
                src[ tmpIndex ] = tmp;
            }
        }
    }

    qDebug() << src;
}

QVector<int> CFastSort::generate( const int size )
{
    QVector< int > rets;
    for( int index = 0; index < size; index++ ){
        rets << QRandomGenerator::global()->bounded( 100 );
    }

    return rets;
}







