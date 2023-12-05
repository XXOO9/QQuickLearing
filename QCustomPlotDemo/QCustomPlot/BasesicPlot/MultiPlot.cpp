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
    QElapsedTimer timer;
    timer.start();
    int graphCnt = m_pPlot->graphCount();
    QCPGraph *graph = nullptr;
    double x = -1;
    double  y = 0;
    for( int index = 0; index < graphCnt; index++ ){
        graph = m_pPlot->graph( index );
        graph->data()->remove( graph->data()->at( 0 )->key );

        x = graph->data()->at( graph->data()->size() - 1 )->key + 1;
        y = qSin( x );
        graph->addData( x, y );
        graph->rescaleAxes();
    }

    qDebug() << "load data " << timer.restart() << " ms";
    m_pPlot->replot( QCustomPlot::RefreshPriority::rpQueuedReplot );
    qDebug() << "plot " << timer.elapsed() << " ms";
}

void MultiPlot::onMouseWheel(QWheelEvent *event)
{
    qDebug() << "2";
}

void MultiPlot::init()
{
    setAcceptedMouseButtons( Qt::AllButtons );

    m_pPlot = new QCustomPlot();
    m_pPlot->plotLayout()->clear();
    m_pPlot->setInteractions( QCP::Interaction::iRangeZoom | QCP::Interaction::iRangeDrag );

    connect( m_pPlot, &QCustomPlot::afterReplot, this, &MultiPlot::onCustomReplot );
    connect( m_pPlot, &QCustomPlot::mouseWheel, this, &MultiPlot::onMouseWheel );
    connect( this, &MultiPlot::widthChanged,  this, &MultiPlot::onUpdateCustomPlotSize );
    connect( this, &MultiPlot::heightChanged, this, &MultiPlot::onUpdateCustomPlotSize );

    //准备初始数据
    QVector< double > x;
    QVector< double > y;

    for( int index = 0; index < 10; index++ ){
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
//            yAxis->setRange( -10, 10 );

//                        xAxis->setRange( 0.0, 13.0 );

            m_pPlot->plotLayout()->addElement( row, column, axisRect );
            index++;
        }
    }

    m_pPlot->replot();
    connect( &m_timer, &QTimer::timeout, this, &MultiPlot::onTimerTimeout, Qt::QueuedConnection );
    m_timer.start( 0 );

}

void MultiPlot::routeMouseEvents(QMouseEvent *event)
{
    if( nullptr == m_pPlot ){
        return;
    }

    QMouseEvent *newEvent = new QMouseEvent( event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers() );

    QCoreApplication::postEvent( m_pPlot, newEvent );
}

void MultiPlot::mousePressEvent(QMouseEvent *event)
{
    //    routeMouseEvents( event );
    if( Qt::LeftButton == event->button() ){
        m_lastPressPos = event->pos();
    }

    m_curAxisRect = m_pPlot->axisRectAt( event->pos() );

}

void MultiPlot::mouseReleaseEvent(QMouseEvent *event)
{

}

void MultiPlot::mouseMoveEvent(QMouseEvent *event)
{
    if( Qt::LeftButton != event->buttons() ){
        return;
    }

    QPointF deltaPos = event->pos() - m_lastPressPos;
    m_lastPressPos = event->pos();

    qDebug() << "diff x = " << deltaPos.x();
    qDebug() << "diff y = " << deltaPos.y();

    if( nullptr == m_curAxisRect ){
        return;
    }
    m_curAxisRect->axis( QCPAxis::AxisType::atLeft, 0 )->moveRange( deltaPos.y() * 0.3 );
    m_curAxisRect->axis( QCPAxis::AxisType::atBottom, 0 )->moveRange( -deltaPos.x() * 0.3 );
    m_pPlot->replot( QCustomPlot::RefreshPriority::rpQueuedReplot );
}

void MultiPlot::wheelEvent(QWheelEvent *event)
{
    qDebug() << "1";
    double ret = event->delta() > 0 ? 0.9 : 1.1;
    if( nullptr == m_curAxisRect ){
        return;
    }
    m_curAxisRect->axis( QCPAxis::AxisType::atLeft, 0 )->scaleRange( ret );
    m_curAxisRect->axis( QCPAxis::AxisType::atBottom, 0 )->scaleRange( ret );
    m_pPlot->replot( QCustomPlot::RefreshPriority::rpQueuedReplot );
}
