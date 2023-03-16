#ifndef CMAINWIDGET_H
#define CMAINWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QElapsedTimer>
#include "./thirdParty/qcustomplot/qcustomplot.h"
#include "CPlotLoadDataThread.h"

namespace Ui {
class CMainWidget;
}

class CMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CMainWidget(QWidget *parent = nullptr);
    ~CMainWidget();

private:
    void oneAsixMultiGraph();

    void onePlotMultiAsixs();

protected slots:
    void onTimerTimeout();

    void onReadyReplot();


private:
    Ui::CMainWidget *ui;
    QCustomPlot *custPlot = nullptr;
    QTimer       m_timer;
    CPlotLoadDataThread m_loadThread;
};

#endif // CMAINWIDGET_H
