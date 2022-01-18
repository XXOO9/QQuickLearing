#ifndef CSQLLITE_H
#define CSQLLITE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

class CSqlLite : public QObject
{
    Q_OBJECT
public:
    explicit CSqlLite(QObject *parent = nullptr);

    //操作表
public:
    bool insert( QString tanleName, QString )

signals:

public slots:

private:
    void initDataBase();

private:
    QSqlDatabase    m_dataBase;
};

#endif // CSQLLITE_H
