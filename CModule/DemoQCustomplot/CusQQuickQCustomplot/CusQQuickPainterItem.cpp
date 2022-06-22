#include "CusQQuickPainterItem.h"

CusQQuickPainterItem::CusQQuickPainterItem()
{
//    drawCircle();
}

CusQQuickPainterItem::~CusQQuickPainterItem()
{

}

void CusQQuickPainterItem::paint(QPainter *painter)
{
    if( nullptr != m_painter ){
        return;
    }

    QPen pen;
    pen.setWidth( 12 );
    pen.setColor( Qt::red );
    m_painter->setPen( pen );
    m_painter->drawRect( 0, 0, 200, 200 );

    update();
}

void CusQQuickPainterItem::init()
{
    paint( m_painter );
}

int CusQQuickPainterItem::width() const
{
    return m_width;
}

void CusQQuickPainterItem::setWidth(int newWidth)
{
    if (m_width == newWidth)
        return;
    m_width = newWidth;
    emit widthChanged();
}

int CusQQuickPainterItem::getHeight() const
{
    return height;
}

void CusQQuickPainterItem::setHeight(int newHeight)
{
    if (height == newHeight)
        return;
    height = newHeight;
    emit heightChanged();
}
