#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocalServer>
#include <QLocalSocket>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

    void sendToClient( QString msg );

    bool satrtExcute();

public slots:
    void onNewConnection();
    void onReadyRead();

private:
    Ui::MainWindow *ui;
    QLocalServer    *m_pLocalServer;
    QLocalSocket    *m_pSocket;
    QProcess         m_process;
};

#endif // MAINWINDOW_H
