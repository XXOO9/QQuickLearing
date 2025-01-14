﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "CWorkThread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void init();

private:
    Ui::Widget *ui;
    CWorkThread w;
};

#endif // WIDGET_H
