#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include <QDateTime>

class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    void testQStringContains();

    void testDateTimeToString();

};

#endif // CINTERACTION_H
