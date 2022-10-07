#include "CusPainter.h"

CusPainter::CusPainter()
{
    qDebug() << "construct CusPainter...";
}

CusPainter::~CusPainter()
{

}

void CusPainter::paint(QPainter *painter)
{
    painter->setPen( QPen( Qt::red ) );

    painter->drawRect( QRect( 0, 0, width() - 5, height() - 5 ) );
    qDebug() << "width = " << width();
}
