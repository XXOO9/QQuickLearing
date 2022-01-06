#ifndef CTESTLISTMODEL_H
#define CTESTLISTMODEL_H

#include <QAbstractListModel>

class CTestListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CTestListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // CTESTLISTMODEL_H
