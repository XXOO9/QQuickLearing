/********************************************************************************
** Form generated from reading UI file 'CMainFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINFRAME_H
#define UI_CMAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainFrame
{
public:

    void setupUi(QWidget *CMainFrame)
    {
        if (CMainFrame->objectName().isEmpty())
            CMainFrame->setObjectName(QString::fromUtf8("CMainFrame"));
        CMainFrame->resize(800, 600);

        retranslateUi(CMainFrame);

        QMetaObject::connectSlotsByName(CMainFrame);
    } // setupUi

    void retranslateUi(QWidget *CMainFrame)
    {
        CMainFrame->setWindowTitle(QCoreApplication::translate("CMainFrame", "CMainFrame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMainFrame: public Ui_CMainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINFRAME_H
