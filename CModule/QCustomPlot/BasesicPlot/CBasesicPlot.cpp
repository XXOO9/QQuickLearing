#include "CBasesicPlot.h"

CBasesicPlot::CBasesicPlot(QQuickPaintedItem *parent) : QQuickPaintedItem(parent)
{
    init();
}

void CBasesicPlot::paint(QPainter *painter)
{
    if( nullptr == m_pPlot ){
        return;
    }

    QPixmap picture( boundingRect().size().toSize() );
    QCPPainter qcppainter( &picture );

    m_pPlot->toPainter( &qcppainter );

    painter->drawPixmap( QPoint(), picture );
}

void CBasesicPlot::updateCustomPlotSize()
{
    if( nullptr == m_pPlot ){
        return;
    }

    m_pPlot->setGeometry( 0, 0, width(), height() );
}

void CBasesicPlot::onCustomReplot()
{
    update();
}

void CBasesicPlot::init()
{
    m_pPlot = new QCustomPlot();

    initPlot();

    m_pPlot->replot();
}

void CBasesicPlot::initPlot()
{
    QCPAxisRect* axisRect = m_pPlot->axisRect();

    // generate some data:
    QVector<double> x( 101 ), y( 101 );   // initialize with entries 0..100
    QVector<double> lx( 101 ), ly( 101 ); // initialize with entries 0..100
    for (int i = 0; i < 101; ++i)
    {
        x[i] = i / 50.0 - 1;              // x goes from -1 to 1
        y[i] = x[i] * x[i];               // let's plot a quadratic function

        lx[i] = i / 50.0 - 1;             //
        ly[i] = lx[i];                    // linear
    }

    //添加坐标轴
    m_pPlot->addGraph();
    m_pPlot->graph( 0 )->setPen( QPen( Qt::red ) );
//    m_pPlot->graph( 0 )->setSelectedPen( QPen( Qt::blue, 2 ) );
    m_pPlot->graph( 0 )->setData( x, y );

    m_pPlot->addGraph();
    m_pPlot->graph( 1 )->setPen( QPen( Qt::blue ) );
    m_pPlot->graph( 1 )->setData( lx, ly );
}
