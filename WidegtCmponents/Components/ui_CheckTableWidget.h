/********************************************************************************
** Form generated from reading UI file 'CheckTableWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKTABLEWIDGET_H
#define UI_CHECKTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckTableWidget
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *CheckTableWidget)
    {
        if (CheckTableWidget->objectName().isEmpty())
            CheckTableWidget->setObjectName(QString::fromUtf8("CheckTableWidget"));
        CheckTableWidget->resize(863, 565);
        gridLayout = new QGridLayout(CheckTableWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(CheckTableWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(CheckTableWidget);

        QMetaObject::connectSlotsByName(CheckTableWidget);
    } // setupUi

    void retranslateUi(QWidget *CheckTableWidget)
    {
        CheckTableWidget->setWindowTitle(QCoreApplication::translate("CheckTableWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckTableWidget: public Ui_CheckTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKTABLEWIDGET_H
