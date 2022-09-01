#ifndef CMODELUSERSELECT_H
#define CMODELUSERSELECT_H

#include <QAbstractListModel>
#include <QDebug>
#include "CUserSelectItem.h"

class CModelUserSelect : public QAbstractListModel
{
    Q_OBJECT

public:

    enum UserItem{
        CheckState = 0,
        PhotoPath,
        UserName,
        UserNumber,
        UserWeight_KG,
        BindDevOrderNumber
    };
    Q_ENUM( UserItem )

    explicit CModelUserSelect(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = UserItem::UserName) const override;
    virtual QHash<int, QByteArray>  roleNames() const override;

private:
    QVector<CUserSelectItem>  m_vecUsers;
};

#endif // CMODELUSERSELECT_H
