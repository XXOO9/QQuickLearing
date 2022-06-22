#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    generateData();
    configGraphLine();
    loadGraph();

//    tmpLoad();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateData()
{
    double tmp = 0;
    for( int i = 0; i < 500; i++ ){
        m_vecXAsix << i;
        m_vecYAsix << i;
        m_vecYAsix2 << i * 1.5;
    }
}

void MainWindow::configGraphLine()
{
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    // 设置坐标轴的范围，以看到所有数据
//    ui->customPlot->xAxis->setRange(0, 120);
//    ui->customPlot->yAxis->setRange(0, 120 );
    ui->customPlot->legend->setVisible(true); // 显示图例

    //设置线的颜色
    ui->customPlot->graph( 0 )->setPen( QPen( Qt::red ) );

    //设置与X轴包围起来的区间颜色
    ui->customPlot->graph( 0 )->setBrush( QBrush( Qt::green ) );

    //自动缩放X轴和Y轴, 使当前的plot刚好能够显示完所有的曲线(如果有多条曲线，则依次设置), 必须在设置了数据过后才生效,这里设置了不会生效
    ui->customPlot->graph( 0 )->rescaleAxes();
    ui->customPlot->graph( 1 )->rescaleAxes(true);

    //设置线的颜色
    ui->customPlot->graph( 1 )->setPen( QPen( Qt::blue ) );

    ui->customPlot->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom );

}

void MainWindow::loadGraph()
{
    ui->customPlot->graph( 0 )->setData( m_vecXAsix, m_vecYAsix );
    ui->customPlot->graph( 0 )->setName( "first graph name" );

    ui->customPlot->graph( 1 )->setData( m_vecXAsix, m_vecYAsix2 );
    ui->customPlot->graph( 1 )->setName( "second graph name" );

    //自动缩放,必须在设置了数据过后才生效
    ui->customPlot->graph( 0 )->rescaleAxes();
    ui->customPlot->graph( 1 )->rescaleAxes(true);

    ui->customPlot->replot();
}

void MainWindow::tmpLoad()
{

    // 添加两个graph
      ui->customPlot->addGraph();
      ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // 第一条曲线颜色
      ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // 第一条曲线和0轴围成区域填充的颜色
      ui->customPlot->addGraph();
      ui->customPlot->graph(1)->setPen(QPen(Qt::red)); // 第二条曲线颜色

      // 生成数据
      QVector<double> x(251), y0(251), y1(251);
      for (int i=0; i<251; ++i)
      {
        x[i] = i;
        y0[i] = qExp(-i/150.0)*qCos(i/10.0); // 指数衰减的cos
        y1[i] = qExp(-i/150.0);              // 衰减指数
      }

      // 配置右侧和顶部轴显示刻度，但不显示标签:
      ui->customPlot->xAxis2->setVisible(true);
      ui->customPlot->xAxis2->setTickLabels(false);
      ui->customPlot->yAxis2->setVisible(true);
      ui->customPlot->yAxis2->setTickLabels(false);

      // 让左边和下边轴与上边和右边同步改变范围
//      connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
//      connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

      // 设置数据点
      ui->customPlot->graph(0)->setData(x, y0);
      ui->customPlot->graph(1)->setData(x, y1);
      //让范围自行缩放，使图0完全适合于可见区域:
      ui->customPlot->graph(0)->rescaleAxes( true );
      // 图1也是一样自动调整范围，但只是放大范围(如果图1小于图0):
      ui->customPlot->graph(1)->rescaleAxes(  );
      // 允许用户用鼠标拖动轴范围，用鼠标滚轮缩放，点击选择图形:
      ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

