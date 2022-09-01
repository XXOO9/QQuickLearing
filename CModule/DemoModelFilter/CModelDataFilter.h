#ifndef CMODELDATAFILTER_H
#define CMODELDATAFILTER_H

#include <QObject>
#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QQmlContext>
#include <QStringList>
#include <QDebug>

class CModelDataFilter : public QObject
{
    Q_OBJECT
public:
    explicit CModelDataFilter(QObject *parent = nullptr);
    void init();

    QSortFilterProxyModel *m_proxyModel = nullptr;
};

#endif // CMODELDATAFILTER_H
