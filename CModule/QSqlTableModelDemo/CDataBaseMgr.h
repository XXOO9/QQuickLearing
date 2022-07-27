#ifndef CDATABASEMGR_H
#define CDATABASEMGR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>

class CDataBaseMgr : public QObject
{
    Q_OBJECT
public:
    explicit CDataBaseMgr(QObject *parent = nullptr);
    bool createConnection();

    void insertNewRecord();

    void deleRecord();

    void query();

    void queryFilter();

    void change();

    void getSpecificRecord();

private:
    void init();

signals:

public slots:

private:
    QSqlTableModel  *m_pMentalTable = nullptr;
    QSqlDatabase m_db;
};

#endif // CDATABASEMGR_H
