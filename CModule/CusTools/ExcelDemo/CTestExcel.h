#ifndef CTESTEXCEL_H
#define CTESTEXCEL_H

#include <QObject>
#include <QDebug>

class CTestExcel : public QObject
{
    Q_OBJECT
public:
    explicit CTestExcel(QObject *parent = nullptr);

    void testImport();

signals:

public slots:
};

#endif // CTESTEXCEL_H
