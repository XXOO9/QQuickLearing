#include "CMoveGrapRangeThread.h"

CMoveGrapRangeThread::CMoveGrapRangeThread()
{

}

void CMoveGrapRangeThread::run()
{
    QCPGraph    *grap = nullptr;
    double x = 0;
    qDebug() << "start move thread";
    forever{
        for( int index = 0; index < m_pPlot->graphCount(); index++ ){
            grap = m_pPlot->graph( index );
            x = grap->data()->at( grap->data()->size() - 1 )->key + 1;
            m_pPlot->axisRect( index )->axis( QCPAxis::AxisType::atBottom, 0 )->setRange( x + 5.0, 15.0, Qt::AlignRight );
            QThread::msleep( 1 );
        }
    }

}
