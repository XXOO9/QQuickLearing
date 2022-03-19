/********************************************************************************
** Form generated from reading UI file 'CMainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWIDGET_H
#define UI_CMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWidget
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *CMainWidget)
    {
        if (CMainWidget->objectName().isEmpty())
            CMainWidget->setObjectName(QString::fromUtf8("CMainWidget"));
        CMainWidget->resize(676, 587);
        pushButton = new QPushButton(CMainWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 80, 75, 23));

        retranslateUi(CMainWidget);

        QMetaObject::connectSlotsByName(CMainWidget);
    } // setupUi

    void retranslateUi(QWidget *CMainWidget)
    {
        CMainWidget->setWindowTitle(QApplication::translate("CMainWidget", "CMainWidget", nullptr));
        pushButton->setText(QApplication::translate("CMainWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMainWidget: public Ui_CMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWIDGET_H
