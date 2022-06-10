#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QVariantMap>
#include <QDebug>
#include <QJsonObject>


class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    Q_INVOKABLE void testFunc();

signals:
    void sigPassJson( QString jsString );
public slots:
};

#endif // CINTERACTION_H
