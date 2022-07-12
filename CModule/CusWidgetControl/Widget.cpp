#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
//    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框窗口
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    this->move( 0,0 );
}

void Widget::on_pushButton_clicked()
{
    setMaximumSize(1000, 400);
    setMinimumSize(1000, 400);
}
