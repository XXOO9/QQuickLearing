#include "CBasesicPlot.h"
#include <QMargins>

CBasesicPlot::CBasesicPlot(QQuickPaintedItem *parent) : QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons( Qt::AllButtons );
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

void CBasesicPlot::getName()
{
    qDebug() << "name";
}

void CBasesicPlot::appendData()
{
    QCPGraph    *graph = m_pPlot->graph( 0 );
    double lastX = graph->data()->at( graph->data()->size()  - 1 )->key;

    double x = lastX + 1;
    double y = QRandomGenerator::global()->bounded( 100 );

    graph->addData( x, y );
    //    qDebug() << "x = " << lastX << " size = " << graph->data()->size();

    m_pPlot->xAxis->setRange( lastX, 50, Qt::AlignRight );

    m_pPlot->replot();
}

void CBasesicPlot::startTimer()
{
    m_timer.start( 0 );
}

void CBasesicPlot::routeMouseEvents(QMouseEvent *event)
{

}

void CBasesicPlot::mousePressEvent(QMouseEvent *event)
{

}

void CBasesicPlot::wheelEvent(QWheelEvent *event)
{
    QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
    QCoreApplication::postEvent( m_pPlot, newEvent );
}

void CBasesicPlot::graphClicked(QCPAbstractPlottable *plottable)
{
    qDebug() << QString( "clilcked on graph %1" ).arg( plottable->name() );
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
    //    qDebug() << "opengl enale = " << m_pPlot->openGl();
    //    qDebug() << "rplot cost " << m_pPlot->replotTime( true );
}

void CBasesicPlot::onTimerTimeout()
{

    QCPGraph    *graph = m_pPlot->graph( 0 );
    double lastX = graph->data()->at( graph->data()->size()  - 1 )->key;

    double x = lastX + 1;
    double y = QRandomGenerator::global()->bounded( 100 );

    graph->addData( x, y );
    //    qDebug() << "x = " << lastX << " size = " << graph->data()->size();

    m_pPlot->xAxis->setRange( lastX, 50, Qt::AlignRight );

    m_pPlot->replot();
}

void CBasesicPlot::init()
{
    m_pPlot = new QCustomPlot();
    //    m_pPlot->setOpenGl( true );
    connect( m_pPlot, &QCustomPlot::afterReplot, this, &CBasesicPlot::onCustomReplot );

    connect( this, &QQuickPaintedItem::widthChanged, this, &CBasesicPlot::updateCustomPlotSize );
    connect( this, &QQuickPaintedItem::heightChanged, this, &CBasesicPlot::updateCustomPlotSize );

    m_pPlot->setInteractions( QCP::iRangeZoom | QCP::iRangeDrag );
    m_pPlot->xAxis->setTickLabels( true );
    m_pPlot->yAxis->setTickLabels( true );

    m_pPlot->axisRect()->setAutoMargins( QCP::MarginSide::msNone );
    m_pPlot->axisRect()->setMargins( QMargins( 10, 10, 10, 10 ) );

    m_pPlot->axisRect()->setRangeZoom( Qt::Horizontal | Qt::Vertical );

//    m_pPlotsetOptimizationFlag(QCP::oHighQualityLegend);

    initTest();

    m_pPlot->replot();
}

void CBasesicPlot::initTest()
{
    QVector<double> x;
    QVector<double> y;

    int initSize = 500;

    for( int index = 0; index < initSize; index++ ){
        x << index;
        y << QRandomGenerator::global()->bounded( 100 );
    }

    m_pPlot->addGraph();
    m_pPlot->graph( 0 )->setData( x, y );

    m_pPlot->xAxis->setRange( 0, 150 );
    m_pPlot->yAxis->setRange( 0, 105 );

    m_pPlot->setMouseTracking( true );

    connect( &m_timer, &QTimer::timeout, this, &CBasesicPlot::onTimerTimeout );
    //    m_timer.start( 200 );

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

    m_pPlot->yAxis->setLabel( "YY" );
    m_pPlot->xAxis->setLabel( "XX" );

    m_pPlot->yAxis->setRange( -2, 2 );
    m_pPlot->xAxis->setRange( -2, 2 );
}
