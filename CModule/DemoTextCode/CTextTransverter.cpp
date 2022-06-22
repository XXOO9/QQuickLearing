#include "CTextTransverter.h"

#include <QFontDatabase>

CTextTransverter::CTextTransverter()
{
    loadCusFont();
    QImage img = createImg( "繁" );

    unsigned short *ptr = getArray( img );

    display( ptr );
}

void CTextTransverter::loadCusFont()
{
    QString executeDir = QCoreApplication::applicationDirPath();
    QString fontName = "CusFont.ttf";

    int fontID = QFontDatabase::addApplicationFont( executeDir + "/" + fontName );
    m_fontRealName = QFontDatabase::applicationFontFamilies( fontID ).first();


    QFontDatabase database;
    foreach (const QString &family, database.families()) {
        qDebug()<<family;
        foreach (const QString &style, database.styles(family)) {
            qDebug()<<" "<<style;
        }
    }
}

QImage CTextTransverter::createImg(QByteArray text)
{
    QString targetText = QString::fromLocal8Bit( text );
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
    painter.setFont( m_fontRealName );

    painter.drawText( img.rect(), Qt::AlignHCenter | Qt::AlignVCenter, targetText );
    img.save( "./WDNMD.png" );
    return img;
}

unsigned short *CTextTransverter::getArray(QImage &img)
{
    qDebug() << "size = " << img.size();

    img = img.mirrored( true, true );
    QMatrix  matrix;
    matrix.rotate( 90.0 );
    img = img.transformed( matrix );

    unsigned short* posArray2 = new unsigned short[16] {0};


    int rowCount = 0;
    int columnCount = 0;
    int totalCount = 0;
    int blackCount = 0;
    int whiteCount = 0;

    unsigned short tmpRowData = 0x0;

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
        qDebug( "%s", qPrintable(QString::number( tmpRowData, 2 ).rightJustified( 16, '0' )));
    }

    qDebug() << "blackCount = " << blackCount;
    qDebug() << "whiteCount = " << whiteCount;

    return posArray2;
}

void CTextTransverter::display( unsigned short *ptr )
{
    unsigned short tmp = 0;
    QString str = "";
    QStringList list;
    QVector<QStringList> vec;
    unsigned short *tmpPtr = ptr;
    for( int row = 0; row < 16; row++ ){
        tmp  = *( tmpPtr + row );
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
