#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include "./CusFiltListModel/CusFiltListModel.h"
#include "CModelUserSelect.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>


class CInteraction : public QObject
{
    Q_OBJECT
public:
    explicit CInteraction(QObject *parent = nullptr);

    void setEnigne(QQmlApplicationEngine *pEngine );

    void setFilterSourceModel( QAbstractItemModel *srcModel );

    Q_INVOKABLE void setVariantList( QVariantList list );

private:
    void registMember();

    void initOrginalFilterModel();

private:
    CusFiltListModel          *m_pFilterModel = nullptr;
    CModelUserSelect           m_srcModel;
    QQmlApplicationEngine     *m_pEngine = nullptr;
    QSortFilterProxyModel      m_orginalFilterModel;
};

#endif // CINTERACTION_H
