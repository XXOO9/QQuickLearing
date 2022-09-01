#ifndef CSQLLITE_H
#define CSQLLITE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QTextCodec>

# pragma execution_character_set( "utf-8");//解决中文乱码问题

class student
{

public:
    student( int id = -1, QString name = "", QString className = "" );
public:
    int m_id;
    QString m_name;
    QString m_className;
};

class CSqlLite : public QObject
{
    Q_OBJECT
public:
    explicit CSqlLite(QObject *parent = nullptr);

    //操作表
public:

    void testFunc();

    //查询所有表名
    void queryTables();

    //插入一条字段
    bool insertIntoStudent( int id, QString stuName, QString className );

    //2022.08.30  心电数据库, 插入
    void insertGECGUserTable( QStringList list );

    void insertIntoCppDepartment();

    int getRowsCount( QString tableName );

    bool deleteFromStudent( int id );

    bool updateStudent( int id, QString key, QString val );

    QVariant querySpecificVal( int id, QString key );
    student queryStudentInfo( int id );
signals:

public slots:

private:
    void initDataBase();

private:
    QSqlDatabase    m_dataBase;

};

#endif // CSQLLITE_H
