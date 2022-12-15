#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include <QJsonValue>
#include <QJSValue>
#include <QJSEngine>

class CInteraction : public QObject
{
    Q_OBJECT
public:
    explicit CInteraction(QObject *parent = nullptr);

    Q_INVOKABLE void test_qml_callback( QVariant parameters, QJSValue func );

    Q_INVOKABLE void changeColor( QJSValue func );

signals:

public slots:
};

#endif // CINTERACTION_H
