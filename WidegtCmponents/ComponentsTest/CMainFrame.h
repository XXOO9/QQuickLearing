#ifndef CMAINFRAME_H
#define CMAINFRAME_H

#include <QWidget>
#include "LoginWidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CMainFrame; }
QT_END_NAMESPACE

class CMainFrame : public QWidget
{
    Q_OBJECT

public:
    CMainFrame(QWidget *parent = nullptr);
    ~CMainFrame();

private:
    Ui::CMainFrame *ui;

    LoginWidget *m_pLogin = nullptr;
};
#endif // CMAINFRAME_H
