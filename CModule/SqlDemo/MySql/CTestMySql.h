
#ifndef CTESTMYSQL_H
#define CTESTMYSQL_H


#include <QObject>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QDebug>


class CTestMySql : public QObject
{
    Q_OBJECT
public:
    explicit CTestMySql(QObject *parent = nullptr);

    static void init();

signals:

};

#endif // CTESTMYSQL_H
