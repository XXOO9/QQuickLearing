#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
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

    connect( ui->pushButton_2, &QPushButton::clicked, this, [=](){
        w.stopDisplay();
    });
}
