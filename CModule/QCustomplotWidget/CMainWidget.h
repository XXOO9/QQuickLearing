#ifndef CMAINWIDGET_H
#define CMAINWIDGET_H

#include <QWidget>
#include <QDebug>
#include "../thirdParty/qcustomplot/qcustomplot.h"

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
    void init();

private:
    Ui::CMainWidget *ui;



    QCustomPlot *m_pPlot = nullptr;
};

#endif // CMAINWIDGET_H
