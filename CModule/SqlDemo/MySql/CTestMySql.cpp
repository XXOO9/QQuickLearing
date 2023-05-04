
#include "CTestMySql.h"
#include "qdebug.h"

CTestMySql::CTestMySql(QObject *parent)
    : QObject{parent}
{

}

void CTestMySql::init()
{
    auto drivers = QSqlDatabase::drivers();

    qDebug() << drivers;
}

