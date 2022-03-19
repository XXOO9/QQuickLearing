#ifndef CMAINWIDGET_H
#define CMAINWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPoint>

namespace Ui {
class CMainWidget;
}

class CMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CMainWidget(QWidget *parent = nullptr);
    ~CMainWidget();

private:

    void init();

    void mousePressEvent( QMouseEvent *event );

    void mouseMoveEvent( QMouseEvent *event );

    void mouseReleaseEvent( QMouseEvent *event );

    void paintEvent( QPaintEvent *event );

public:
    Ui::CMainWidget *ui;
    QPixmap     m_pix;
    QPoint      m_lastPos;
    QPoint      m_endPos;
    QVector<QPoint> m_lines;
    bool        m_isPressed{false};
    QPen        m_pen;
};

#endif // CMAINWIDGET_H
