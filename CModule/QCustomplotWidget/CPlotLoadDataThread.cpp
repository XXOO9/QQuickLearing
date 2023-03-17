#include "CPlotLoadDataThread.h"

CPlotLoadDataThread::CPlotLoadDataThread()
{

}

void CPlotLoadDataThread::run()
{
    qDebug() << "run Thread ID = " << QThread::currentThreadId();
    QElapsedTimer timer;
    QElapsedTimer timer1;

    int graphCnt = m_pPlot->graphCount();
    while( 1 ){
        timer.restart();
        int boundX = 0;

        for( int index = 0; index < graphCnt; index++ ){
            QCPGraph    *curGraph = m_pPlot->graph( index );
            int lastX = curGraph->data()->at( curGraph->data()->size() - 1 )->key;
            boundX = lastX;
            double x = ++lastX;
            double y = QRandomGenerator::global()->bounded( 5 );
            curGraph->addData( x, y );

//            timer1.restart();
            m_pPlot->axisRect( index )->axis( QCPAxis::AxisType::atBottom )->setRange( x, 5, Qt::AlignRight);
//            qDebug() << "set range cost " << timer1.elapsed() << " ms";
        }
        qDebug() << "load data cost " << timer.elapsed() << " ms";
//        emit sigLoadFinished();
//        QThread::msleep( 5 );
    }
}
