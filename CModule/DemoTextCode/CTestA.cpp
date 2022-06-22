#include "CTestA.h"

CTestA::CTestA()
{
    test();
//        testFunc2();
}

QImage CTestA::createImg()
{
    QString targetText = QString::fromLocal8Bit( "你" );
    QSize size( 16, 16 );
    QImage img( size, QImage::Format_ARGB32 );
    img.fill( Qt::white );


    QPainter painter( &img );
    painter.setCompositionMode( QPainter::CompositionMode_SourceOver );

    QPen pen = painter.pen();
    pen.setColor( Qt::black );

    QFont font = painter.font();
    font.setPixelSize( 16 );

    painter.setPen( pen );
    painter.setFont( font );

    painter.drawText( img.rect(), Qt::AlignHCenter | Qt::AlignVCenter, targetText );

    img.save( "./code.png" );
    return img;
}

void CTestA::getArray(QImage &img)
{
    qDebug() << "size = " << img.size();

    img = img.mirrored( true, true );
    QMatrix  matrix;
    matrix.rotate( 90.0 );
    img = img.transformed( matrix );

    unsigned short  posArray2[16] = { 0 };

    int rowCount = 0;
    int columnCount = 0;
    int totalCount = 0;
    int blackCount = 0;
    int whiteCount = 0;

    unsigned short tmpRowData = 0x0;

    qDebug() << "hex1 = " << QString::number( tmpRowData, 16 );

    tmpRowData <<= 3;

    qDebug() << "hex2 = " << QString::number( tmpRowData, 16 );

    QColor tmpColor;
    for( quint8 row = 0; row < 16; row++ ){
        tmpRowData = 0x0;
        whiteCount = 0;
        blackCount = 0;
        for( quint8 column = 0; column < 16; column++ ){
            tmpColor = img.pixel( row, column );

            if( tmpColor == Qt::white ){
                whiteCount++;
            }

            //不是白色就是黑色
            if( tmpColor != Qt::white ){
                blackCount++;
                tmpRowData |= 1 << column;
            }
            totalCount++;
        }

        posArray2[row] = tmpRowData;
        qDebug() << "-----------------------------------------Row: " << row << " white: " << whiteCount << " black: " << blackCount;
        qDebug() << "-----------------------------------------" << tmpRowData;
        qDebug( "%s",qPrintable(QString::number( tmpRowData, 2 ).rightJustified( 16, '0' )));
    }

    qDebug() << "blackCount = " << blackCount;
    qDebug() << "whiteCount = " << whiteCount;

    //    display( posArray );
    display_version2( posArray2 );

}

void CTestA::Vector2Array(QVector<int> &vecPos)
{
    char posArray[16][16] = { 0 };

    const char *rowData = nullptr;
    for( int row = 0; row < 16; row++ ){
        for( int column = 0; column < 16; column++ ){
            rowData = qPrintable(QString::number( vecPos[row], 2 ).rightJustified( 16, '0' ) );

            printf( "row = %s\n", rowData );
        }
    }
}

void CTestA::test()
{
    QImage img = createImg();
    getArray( img );

    //    Vector2Array( vec );
}

void CTestA::testFunc()
{
    int tmpRowData = 0x0;

    tmpRowData = 1 << 1;

    qDebug("%s",qPrintable(QString::number(tmpRowData,2).rightJustified(16,'0')));
    tmpRowData |= 1 << 2;
    qDebug("%s",qPrintable(QString::number(tmpRowData,2).rightJustified(16,'0')));
    tmpRowData |= 1 << 3;
    qDebug("%s",qPrintable(QString::number(tmpRowData,2).rightJustified(16,'0')));
    tmpRowData |= 1 << 4;
    qDebug("%s",qPrintable(QString::number(tmpRowData,2).rightJustified(16,'0')));
}

void CTestA::testFunc2()
{
    QString str = "123456789";
    QStringList list = str.split( QString() );
    qDebug() << "list = " << list;
}

void CTestA::display(char (*ptr)[16])
{
    int whiteCount = 0;
    int blackCount = 0;
    for( int row = 0; row < 16; row++ ){
        whiteCount = 0;
        blackCount = 0;
        for( int column = 0; column < 16; column++ ){

            char tmp = ptr[row][column];
            if( tmp == '1' ){
                printf( "%s", "* " );
                blackCount++;
            }else{
                printf( "%s", "  " );
                whiteCount++;
            }
        }
        printf( "\n" );
    }
}

void CTestA::display_version2(unsigned short *ptr)
{
    unsigned short tmp = 0;
    QString str = "";
    QStringList list;
    QVector<QStringList> vec;
    for( int row = 0; row < 16; row++ ){
        tmp  = *( ptr + row );
        str = QString::number(tmp,2).rightJustified(16,'0');
        list = str.split( QString() );
        list.removeFirst();
        list.removeLast();
        vec << list;
    }

    foreach (auto vecEle, vec) {
        foreach (auto listEle, vecEle) {
            if( listEle == "0" ){
                printf( "  " );
            }
            if( listEle == "1" ){
                printf( "* " );
            }
        }

        printf("\n");
    }

}
