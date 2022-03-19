#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocalSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initClient();

    void sendMsgToServer( QString msg );

public slots:
    void onNewMsgAvailable();


private:
    Ui::MainWindow *ui;
    QLocalSocket    *m_pSocket;
};

#endif // MAINWINDOW_H
