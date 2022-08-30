#ifndef CLISTMODEL_H
#define CLISTMODEL_H

#include <QAbstractListModel>
#include <QDebug>

class CListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum CusRoleName{
        Role_A = 0,
        Role_B,
        Role_C,
        Role_D
    };
    Q_ENUM( CusRoleName )
    explicit CListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = CusRoleName::Role_A) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    void initDataModel();

private:
    QList< QMap< CusRoleName, QString > >   m_listDataModel;
};

#endif // CLISTMODEL_H
