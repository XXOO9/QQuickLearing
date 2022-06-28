#include "CusQQuickPainterItem.h"

CusQQuickPainterItem::CusQQuickPainterItem(QQuickPaintedItem *parent)
{
    m_pCustomplot = new QCustomPlot();
    connect( m_pCustomplot, &QCustomPlot::afterReplot, this, &CusQQuickPainterItem::onCustomPlotReplot );
    connect( this, &QQuickPaintedItem::widthChanged,  this, &CusQQuickPainterItem::updateCustomPlotSize );
    connect( this, &QQuickPaintedItem::heightChanged, this, &CusQQuickPainterItem::updateCustomPlotSize );
}

void CusQQuickPainterItem::init()
{
    updateCustomPlotSize();
    m_pCustomplot->addGraph();
    m_pCustomplot->graph( 0 )->setPen( QPen(Qt::red) );
}

void CusQQuickPainterItem::paint(QPainter *painter)
{
    qDebug() << "paint";
    if( nullptr == m_pCustomplot ){
        return;
    }

    QPixmap    picture( boundingRect().size().toSize() );
    QCPPainter qcpPainter( &picture );
    m_pCustomplot->toPainter( &qcpPainter );
    setRenderTarget(QQuickPaintedItem::FramebufferObject);

    painter->drawPixmap( QPoint(), picture );
}

void CusQQuickPainterItem::updateCustomPlotSize()
{
    if( nullptr != m_pCustomplot )
    {
        m_pCustomplot->setGeometry(0, 0, (int)width(), (int)height());
        m_pCustomplot->setViewport(QRect(0, 0, (int)width(), (int)height()));
    }
}

void CusQQuickPainterItem::onCustomPlotReplot()
{
    qDebug() << "on replot";
    update();
}
