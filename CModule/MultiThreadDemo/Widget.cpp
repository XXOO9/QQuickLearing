#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    qDebug() << "main thread ID = " << QThread::currentThreadId();
    ui->setupUi(this);
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    connect( ui->pushButton, &QPushButton::clicked, this, [=](){
        w.startDisplay();
    });

    w.m_func.testFunc();

    connect( ui->pushButton_2, &QPushButton::clicked, this, [=](){
        w.stopDisplay();
    });
}
