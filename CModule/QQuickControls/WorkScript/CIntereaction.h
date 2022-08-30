#ifndef CINTEREACTION_H
#define CINTEREACTION_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QElapsedTimer>


class CIntereaction : public QObject
{
    Q_OBJECT
public:
    explicit CIntereaction(QObject *parent = nullptr);

    Q_INVOKABLE QVariantList getData();

    void generateData();

    static QString convert( const QVariantMap &srcMap );

    QVariantList m_dataList;

};

#endif // CINTEREACTION_H
