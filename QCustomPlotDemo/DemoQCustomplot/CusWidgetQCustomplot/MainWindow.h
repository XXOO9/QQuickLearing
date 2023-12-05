#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMath>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void generateData();

    void configGraphLine();

    void loadGraph();

    void tmpLoad();

private:
    Ui::MainWindow *ui;
    QVector<double>  m_vecXAsix;
    QVector<double>  m_vecYAsix;
    QVector<double>  m_vecYAsix2;
};
#endif // MAINWINDOW_H
