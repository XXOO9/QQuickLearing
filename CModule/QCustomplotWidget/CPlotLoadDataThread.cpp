#include "CPlotLoadDataThread.h"
#include <omp.h>

CPlotLoadDataThread::CPlotLoadDataThread()
{

}

void CPlotLoadDataThread::run()
{
    qDebug() << "run Thread ID = " << QThread::currentThreadId();
    QElapsedTimer timer;
    QElapsedTimer timer1;
    QCPGraph    *curGraph = nullptr;
    double x = 0;

    int graphCnt = m_pPlot->graphCount();
    while( 1 ){
        double boundX = 0;

        double y = QRandomGenerator::global()->bounded( 5 );
        timer.restart();
#pragma omp parallel
        {
            for( int index = 0; index < graphCnt; index++ ){
                curGraph = m_pPlot->graph( index );
                double lastX = curGraph->data()->at( curGraph->data()->size() - 1 )->key;
                boundX = lastX;
                x = ++lastX;

                curGraph->addData( x, y );

                m_pPlot->axisRect( index )->axis( QCPAxis::AxisType::atBottom )->setRange( x, 5, Qt::AlignRight);
            }
        }

        qDebug() << "load data cost " << timer.elapsed() << " ms";
    }
}
