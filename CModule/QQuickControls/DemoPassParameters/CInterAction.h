#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>

class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);

    Q_INVOKABLE void test_variant( QVariantMap val );
    Q_INVOKABLE void test_vector();
    Q_INVOKABLE void test_variantList( QVariantList list );
};

#endif // CINTERACTION_H
