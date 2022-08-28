#ifndef DEMOFILTERMODEL_H
#define DEMOFILTERMODEL_H

#include <QObject>
#include <QDebug>
#include <QSortFilterProxyModel>

class DemoFilterModel : public QSortFilterProxyModel
{
public:
    DemoFilterModel();
    virtual ~DemoFilterModel() override;
};

#endif // DEMOFILTERMODEL_H
