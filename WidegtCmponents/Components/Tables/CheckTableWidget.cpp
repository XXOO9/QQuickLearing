#include "CheckTableWidget.h"
#include "ui_CheckTableWidget.h"

CheckTableWidget::CheckTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckTableWidget)
{
    ui->setupUi(this);

    m_pTableModel = new CusTableModel( this );
    m_pHeaderView = new QHeaderView( Qt::Horizontal, this );

    ui->tableView->setItemDelegateForColumn( 0, new CusCheckBox() );
    ui->tableView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

    ui->tableView->setModel( m_pTableModel );
    m_pHeaderView->setModel( m_pTableModel );
    ui->tableView->setHorizontalHeader( m_pHeaderView );

}

CheckTableWidget::~CheckTableWidget()
{
    delete ui;
}
