#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "Components_global.h"

namespace Ui {
class LoginWidget;
}

class COMPONENTS_EXPORT LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
