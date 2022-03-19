#include "CMainWidget.h"
#include "ui_CMainWidget.h"

#include <QMouseEvent>
#include <QDebug>

CMainWidget::CMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainWidget)
{
    ui->setupUi(this);
//    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
//    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框窗口
//    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    m_pix = QPixmap( 500, 500 );
    m_pix.fill( Qt::white );
    init();
    resize( 500, 500 );
}

CMainWidget::~CMainWidget()
{
    delete ui;
}

void CMainWidget::init()
{
    connect( ui->pushButton, &QPushButton::clicked, [=](){
        m_lines.clear();
        update();
        qDebug() << "state  = " << m_isPressed;
    });

}

void CMainWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
    m_isPressed = true;
    qDebug() << "pressed pos = " << event->pos();
    update();
}

void CMainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if( m_isPressed ){
        m_lines << event->pos();
        update();
    }

}

void CMainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
    m_isPressed = false;
    qDebug() << "Release pos = " << event->pos();
    qDebug() << "size = " << m_lines.size();
    update();
}

void CMainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth( 5 );
    pen.setColor( Qt::black );
    pen.setStyle( Qt::SolidLine );
    painter.setPen( pen );
    painter.drawLines( m_lines );
}
