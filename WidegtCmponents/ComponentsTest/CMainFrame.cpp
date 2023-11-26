#include "CMainFrame.h"
#include "ui_CMainFrame.h"

CMainFrame::CMainFrame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CMainFrame)
{
    ui->setupUi(this);

    m_pLogin = new LoginWidget( this );
}

CMainFrame::~CMainFrame()
{
    delete ui;
}

