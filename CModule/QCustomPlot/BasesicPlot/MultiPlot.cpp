#include "MultiPlot.h"

MultiPlot::MultiPlot()
{

}

void MultiPlot::paint(QPainter *painter)
{
    if( nullptr != m_pPlot ){
        m_pPlot->deleteLater();
        m_pPlot = nullptr;
    }
}

void MultiPlot::updateCustomPlotSize()
{
    if( nullptr == m_pPlot ){
        return;
    }

    m_pPlot->setGeometry( 0, 0, width(), height() );
}

void MultiPlot::onCustomReplot()
{
    update();
}

void MultiPlot::init()
{
    m_pPlot = new QCustomPlot();
}
