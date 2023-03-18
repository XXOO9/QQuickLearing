﻿#include "MultiPlot.h"

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
    //    qDebug() << "draw cost 1" << timer.restart() << " ms";

    QCPPainter qcppainter( &picture );
    //    qDebug() << "draw cost 2" << timer.restart() << " ms";

    m_pPlot->toPainter( &qcppainter );
//    qDebug() << "draw cost 3" << timer.restart() << " ms";

    painter->drawPixmap( QPoint(), picture );
    //    qDebug() << "draw cost 4" << timer.elapsed() << " ms";

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

void MultiPlot::onTimerTimeout()
{
    int graphCnt = m_pPlot->graphCount();

    QCPGraph *graph = nullptr;

    double x = -1;
    double  y = 0;

    QElapsedTimer timer;

    for( int index = 0; index < graphCnt; index++ ){
        graph = m_pPlot->graph( index );
        x = graph->data()->at( graph->data()->size() - 1 )->key + 1;
        y = qSin( x );
        graph->addData( x, y );

#ifndef USE_THREAD_MOVE_RANGE_FLAG
        m_pPlot->axisRect( index )->axis( QCPAxis::AxisType::atBottom, 0 )->setRange( x + 5.0, 15.0, Qt::AlignRight );
#endif

    }
    m_pPlot->replot( QCustomPlot::RefreshPriority::rpQueuedReplot );
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
        y << qSin( index );
    }

    int rowCnt = 32;
    int columnCnt = 32;
    int index = 0;

    for( int row = 0; row < rowCnt; row++ ){
        for( int column = 0; column < columnCnt; column++ ){
            QCPAxisRect *axisRect = new QCPAxisRect( m_pPlot );

            axisRect->setAutoMargins( QCP::MarginSide::msNone );
            axisRect->setMargins( QMargins( 5, 5, 5, 5 ) );
            QCPGraph *graph = m_pPlot->addGraph( axisRect->axis( QCPAxis::AxisType::atBottom ), axisRect->axis( QCPAxis::AxisType::atLeft ) );
            graph->setData( x, y );

            QCPAxis *xAxis = axisRect->axis( QCPAxis::AxisType::atBottom, 0 );
            QCPAxis *yAxis = axisRect->axis( QCPAxis::AxisType::atLeft, 0 );

            xAxis->setTicks( false );
            yAxis->setTicks( false );

            yAxis->setLabelPadding( 0 );
            yAxis->setLabel( QString::number( index ) );
            yAxis->setRange( -1.1, 1.1 );

            m_pPlot->plotLayout()->addElement( row, column, axisRect );
            index++;
        }
    }

    m_pPlot->replot();
    connect( &m_timer, &QTimer::timeout, this, &MultiPlot::onTimerTimeout, Qt::QueuedConnection );

#ifdef USE_THREAD_MOVE_RANGE_FLAG
    m_moveRangeThread.m_pPlot = this->m_pPlot;
    m_moveRangeThread.start( QThread::HighPriority );
    m_timer.start( 10 );
#else
    m_timer.start( 0 );
#endif







}
