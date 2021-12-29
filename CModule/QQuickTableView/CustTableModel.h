#ifndef CUSTTABLEMODEL_H
#define CUSTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QHash>
#include "CTableModelRowData.h"


using namespace ColumnEnums;
typedef QHash<ColumnIndex, CTableModelRowData> rowDatas;
class CustTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:


    explicit CustTableModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool appendRow( rowDatas rowData );
    bool isUniqueble( QString uniqueString );

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    QHash<int, QByteArray> roleNames() const override;

    int Columns() const;
    void setColumns(int Columns);

    QString getValue( ColumnIndex column, int row );

private:
    QVector< rowDatas >                               m_vecDatas;
    QStringList                                       m_roleNamesList;
    int                                               m_Columns;
};

#endif // CUSTTABLEMODEL_H
