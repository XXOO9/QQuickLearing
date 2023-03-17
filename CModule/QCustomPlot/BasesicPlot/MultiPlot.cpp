#include "MultiPlot.h"

MultiPlot::MultiPlot(QQuickPaintedItem *parent) : QQuickPaintedItem( parent )
{
    init();
}

void MultiPlot::paint(QPainter *painter)
{
    if( nullptr == painter ){
        return;
    }

    QElapsedTimer timer;
    timer.restart();

    QPixmap picture( boundingRect().size().toSize() );
    qDebug() << "draw cost 1" << timer.restart() << " ms";

    QCPPainter qcppainter( &picture );
    qDebug() << "draw cost 2" << timer.restart() << " ms";

    m_pPlot->toPainter( &qcppainter );
    qDebug() << "draw cost 3" << timer.restart() << " ms";

    painter->drawPixmap( QPoint(), picture );
    qDebug() << "draw cost 4" << timer.elapsed() << " ms";

}

void MultiPlot::onCustomReplot()
{
    update();
}

void MultiPlot::onUpdateCustomPlotSize()
{
    if( nullptr == m_pPlot ){
        return;
    }

    m_pPlot->setGeometry( 0, 0, width(), height() );
}

void MultiPlot::init()
{
    m_pPlot = new QCustomPlot();
    connect( m_pPlot, &QCustomPlot::afterReplot, this, &MultiPlot::onCustomReplot );
    connect( this, &MultiPlot::widthChanged,  this, &MultiPlot::onUpdateCustomPlotSize );
    connect( this, &MultiPlot::heightChanged, this, &MultiPlot::onUpdateCustomPlotSize );
    m_pPlot->plotLayout()->clear();

    //准备初始数据
    QVector< double > x;
    QVector< double > y;

    for( int index = 0; index < 5; index++ ){
        x << index;
        y << QRandomGenerator::global()->bounded( 5 );
    }

    for( int row = 0; row < 32; row++ ){
        for( int column = 0; column < 32; column++ ){
            QCPAxisRect *axisRect = new QCPAxisRect( m_pPlot );
            QCPGraph *graph = m_pPlot->addGraph( axisRect->axis( QCPAxis::AxisType::atBottom ), axisRect->axis( QCPAxis::AxisType::atBottom ) );
            graph->setData( x, y );
            m_pPlot->plotLayout()->addElement( row, column, axisRect );
        }
    }

    m_pPlot->replot();

}
