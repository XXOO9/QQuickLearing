#pragma once

#include <QCheckBox>
#include <QObject>
#include <QStyledItemDelegate>
#include <QWidget>
#include <QCheckBox>
#include <QDebug>


class CusCheckBox : public QStyledItemDelegate
{
    Q_OBJECT
public:
    CusCheckBox( QObject *parent = nullptr );
    virtual ~CusCheckBox();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void paintCheckBos(QPainter *painter );
private:
    virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;

};
