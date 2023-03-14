#include "CMainWidget.h"
#include "ui_CMainWidget.h"

CMainWidget::CMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainWidget)
{
    ui->setupUi(this);
}

CMainWidget::~CMainWidget()
{
    delete ui;
}

void CMainWidget::init()
{
    m_pPlot = new QCustomPlot( this );


}
