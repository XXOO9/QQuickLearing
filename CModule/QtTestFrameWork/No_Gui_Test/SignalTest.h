#ifndef SINGALTEST_H
#define SINGALTEST_H

#include <QObject>

class SignalTest : public QObject
{
    Q_OBJECT
public:
    explicit SignalTest(QObject *parent = nullptr);

signals:
    void sigSendMsg( QString content );
    void sigSendMultiArgs( QString arg1, QString arg2 );

public slots:
    void onSendMsg( QString content );
};

#endif // SINGALTEST_H
