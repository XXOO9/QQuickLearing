#ifndef CABSTRACTTABLEMODEL_H
#define CABSTRACTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
class CTableCell;
class CAbstractTableModel;

class CAbstractTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum CellRoles{
        Cell_DisplayRole = 0,
    };
     Q_ENUM( CellRoles )
public:
    explicit CAbstractTableModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    QVector< QHash< int, CTableCell > > m_vecDatas;
};

class CTableCell
{
public:
    CTableCell();
    QString value( CAbstractTableModel::CellRoles roleName );
private:
    QString     m_displayValue = "";
};

#endif // CABSTRACTTABLEMODEL_H
