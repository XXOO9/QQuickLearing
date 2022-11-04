#ifndef CUSDATEMODEL_H
#define CUSDATEMODEL_H

#include <QAbstractListModel>
#include <QDebug>

class ElementDateInfo{
public:
    enum InfoElement{
        Hour = 0,
        DayIndex,
        TimeCnt,
        Today,
    };

    int  m_hour = 0;
    int  m_timeCnt = 0;
    int m_dayIndex = 0;
    bool m_isToday = false;

};

class CusDateModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CusDateModel(QObject *parent = nullptr);

    //根据指定的月份刷新日期
    void refreshDateModel(const int &weekDay, const int &days );

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override ;

private:
    QVector<ElementDateInfo>    m_vecTotalInfos;
};

#endif // CUSDATEMODEL_H
