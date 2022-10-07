#ifndef CUSFILTLISTMODEL_H
#define CUSFILTLISTMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>
#include "../CModelUserSelect.h"

class CusFiltListModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    CusFiltListModel();

    virtual ~CusFiltListModel() override;

    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

    QString m_targetDepartmentName = "departmentName_B";
};

#endif // CUSFILTLISTMODEL_H
