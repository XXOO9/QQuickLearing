#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initConnection();

    void startEmitSig();



signals:
    void sigStartTimer();
    void sigTestFuncFinished();
public slots:
    void onTimeout();

    void onStartTimer();

    void callFunc();

private:
    Ui::MainWindow *ui;
    QTimer          m_timer;
};

#endif // MAINWINDOW_H
