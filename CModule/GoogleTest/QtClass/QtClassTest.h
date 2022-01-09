#ifndef QTCLASSTEST_H
#define QTCLASSTEST_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>

class QtClassTest : public QObject
{
    Q_OBJECT
public:
    explicit QtClassTest(QObject *parent = nullptr);
    virtual ~QtClassTest() override;

    QString display();

    void initTimer();

    void startTimer();
    bool isFinished();


signals:


public slots:


private:
    bool    m_isFinished{ false };
    QTimer  m_Timer;
};

#endif // QTCLASSTEST_H
