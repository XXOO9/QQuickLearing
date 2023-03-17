#include "CMainWidget.h"
#include "ui_CMainWidget.h"

CMainWidget::CMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainWidget)
{

    ui->setupUi(this);
    this->resize( 1920, 1080 );

//    oneAsixMultiGraph();
    onePlotMultiAsixs();
}

CMainWidget::~CMainWidget()
{
    delete ui;
}

void CMainWidget::oneAsixMultiGraph()
{
    custPlot = new QCustomPlot( this );

    custPlot->setGeometry( 0, 0, width(), height() );

    QVector< double > x1;
    QVector< double > y1;

    QVector< double > x2;
    QVector< double > y2;

    QCPGraph *graph1 = custPlot->addGraph();
    QCPGraph *graph2 = custPlot->addGraph();
    graph2->setPen( QPen( Qt::red ) );

    int cnt = 20;
    for( int index = 0; index < cnt; index++ ){
        x1 << index;
        y1 << QRandomGenerator::global()->bounded( 5 );
    }

    for( int index = 0; index < cnt; index++ ){
        x2 << index;
        y2 << QRandomGenerator::global()->bounded( 5 );
    }

    graph1->setData( x1, y1 );
    graph2->setData( x2, y2 );

    custPlot->xAxis->setRange( 0, cnt );

    custPlot->replot();


    qDebug() << custPlot->graphCount();
}

void CMainWidget::onePlotMultiAsixs()
{
    custPlot = new QCustomPlot( this );
//    custPlot->setOpenGl( true );
    custPlot->setGeometry( 0, 0, width(), height() );
    custPlot->plotLayout()->clear();

    int rowCnt = 32;
    int columnCnt = 32;
    int outsideMargin = 5;
    QElapsedTimer timer;

    QVector< double > x;
    QVector< double > y;

    for( int index = 0; index < 5; index++ ){
        x << index;
        y << QRandomGenerator::global()->bounded( 5 );
    }


    timer.start();
    for( int column = 0; column < columnCnt; column++ ){
        for( int row = 0; row < rowCnt; row++ ){
            QCPAxisRect *tmp = new QCPAxisRect( custPlot );
            tmp->setAutoMargins( QCP::MarginSide::msNone );
            tmp->setMargins( QMargins( outsideMargin, outsideMargin, outsideMargin, outsideMargin ) );

            QCPGraph *tmpGraph =  custPlot->addGraph( tmp->axis( QCPAxis::atBottom ), tmp->axis( QCPAxis::atLeft ) );
            tmpGraph->setData( x, y );

            custPlot->plotLayout()->addElement( row, column, tmp );
        }
    }

    qDebug() << "init cost " << timer.elapsed() << " ms";
    qDebug() << "grap cnt = " << custPlot->graphCount();

    connect( &m_loadThread, &CPlotLoadDataThread::sigLoadFinished, this, &CMainWidget::onReadyReplot, Qt::QueuedConnection );
    m_loadThread.m_pPlot = custPlot;
    m_loadThread.start();

    connect( &m_timer, &QTimer::timeout, this, &CMainWidget::onTimerTimeout, Qt::QueuedConnection );

    m_timer.start( 500 );
}

void CMainWidget::onTimerTimeout()
{
//    int graphCnt = custPlot->graphCount();
//    QElapsedTimer timer;
//    timer.start();
//    int boundX = 0;
//    for( int index = 0; index < graphCnt; index++ ){
//        QCPGraph    *curGraph = custPlot->graph( index );
//        int lastX = curGraph->data()->at( curGraph->data()->size() - 1 )->key;
//        boundX = lastX;
//        double x = ++lastX;
//        double y = QRandomGenerator::global()->bounded( 5 );

//        curGraph->addData( x, y );

//        custPlot->axisRect( index )->axis( QCPAxis::AxisType::atBottom )->setRange( x, 5, Qt::AlignRight);
//    }

//    qDebug() << "load data cost " << timer.restart() << " ms";
    custPlot->replot();
//    qDebug() << "replot cost " << timer.elapsed() << " ms";
}

void CMainWidget::onReadyReplot()
{
    QElapsedTimer timer;
    timer.restart();
    custPlot->replot();
    qDebug() << "replot cost " << timer.elapsed() << " ms";
}
