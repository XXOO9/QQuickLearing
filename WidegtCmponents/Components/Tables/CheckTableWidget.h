#pragma once

#include <QWidget>
#include <QTableView>
#include "CusTableModel.h"
#include "Components_global.h"
#include <QHeaderView>
#include "CusCheckBox.h"

namespace Ui {
class CheckTableWidget;
}

class COMPONENTS_EXPORT CheckTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CheckTableWidget(QWidget *parent = nullptr);
    ~CheckTableWidget();

private:
    Ui::CheckTableWidget *ui;

    CusTableModel   *m_pTableModel = nullptr;
    QHeaderView     *m_pHeaderView = nullptr;
};

