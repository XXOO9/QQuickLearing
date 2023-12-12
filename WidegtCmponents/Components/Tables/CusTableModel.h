#pragma once

#include <QAbstractTableModel>
#include <QDebug>
#include "Components_global.h"

class TableColumnItems;

class COMPONENTS_EXPORT CusTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CusTableModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QVector< TableColumnItems > m_vecDatas;
};

class TableColumnItems{
public:
    QVariant getIndexVal( const int index );
    void setIndexVal( const QVariant &val, const int index );
    bool    checked = false;
    QString name    = "Empty_Name";
    QString sex     = "Empty_Sex";
};

