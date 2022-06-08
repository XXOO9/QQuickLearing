#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QDateTime>


void func1()
{
    QDateTime today = QDateTime::currentDateTime();
    QString date = today.date().toString("yyyyMMdd");
    QDateTime queryDay = QDateTime::fromString(  date + " 000000", "yyyyMMddhhmmss" );
    qDebug() << "query day = " << queryDay;

    today = today.addMonths( -3 );
    qDebug() << "today = " << today;
}

int main(int argc, char *argv[])
{
    func1();
    return 0;
}
