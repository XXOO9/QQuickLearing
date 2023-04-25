#include "CPainterDrawBoard.h"

CPainterDrawBoard::CPainterDrawBoard(QQuickPaintedItem *parent)
{
    setFillColor( Qt::gray );
    setAcceptedMouseButtons( Qt::AllButtons );
}

CPainterDrawBoard::~CPainterDrawBoard()
{

}

void CPainterDrawBoard::paint(QPainter *painter)
{
    if( nullptr == painter ){
        return;
    }

    static QPen pen( Qt::black );
    pen.setWidth( 2 );
    painter->setPen( pen );
    painter->drawPoints( m_path );
    update();
}

void CPainterDrawBoard::mouseMoveEvent(QMouseEvent *event)
{
    m_path << event->pos();
    update();
}

void CPainterDrawBoard::setSavePath(const QString &savePath)
{
    m_savePath = savePath;
}

void CPainterDrawBoard::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

void CPainterDrawBoard::clear()
{
    m_path.clear();
    m_pixmap = QPixmap();
}

void CPainterDrawBoard::save(QObject *obj)
{
    if( nullptr == obj ){
        return;
    }

    m_pItem = qobject_cast< QQuickItem* >( obj );

    m_grab_result = m_pItem->grabToImage();

    QQuickItemGrabResult * grabResult = m_grab_result.data();

    connect( grabResult, &QQuickItemGrabResult::ready, [this](){
        QImage img = m_grab_result->image();

        img.save( m_savePath + m_fileName );
    });


}

void CPainterDrawBoard::mousePressEvent(QMouseEvent *event)
{

}

void CPainterDrawBoard::mouseReleaseEvent(QMouseEvent *event)
{

}
