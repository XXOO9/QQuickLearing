#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    Q_INVOKABLE void test_variant( QVariantMap val );
    Q_INVOKABLE void test_vector();
    Q_INVOKABLE void test_variantList( QVariantList list );

    Q_INVOKABLE QJsonArray test_JsonArray_to_qml();
    Q_INVOKABLE QVariantMap test_JsonObject_to_qml();
    Q_INVOKABLE QJsonArray test_JsonArrayObject_to_qml();
    Q_INVOKABLE QVariantMap test_VariantList_to_qml();
};

#endif // CINTERACTION_H
