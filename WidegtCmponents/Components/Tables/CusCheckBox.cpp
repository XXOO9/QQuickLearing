#include "CusCheckBox.h"
#include <QStyleOptionViewItem>

#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QRect>

CusCheckBox::CusCheckBox(QObject *parent)
{

}

CusCheckBox::~CusCheckBox()
{

}

void CusCheckBox::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    bool ok = index.data( -1 ).toBool();
    painter->save();
    QRect rect( option.rect );
    painter->drawRect( rect );

    painter->fillRect( rect, ok ? Qt::green : Qt::red );
    painter->restore();
    //    qDebug() << "patient...";
}


bool CusCheckBox::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if( event->type() == QEvent::MouseButtonRelease ){
        qDebug() << "release...";
        bool ok = index.data( -1 ).toBool();
        auto model = const_cast<QAbstractItemModel*>( index.model() );
        model->setData( index, !ok, -1 );
    }

    if( event->type() == QMouseEvent::Enter ){
        qDebug() << "mouse enter...";
    }

    return true;
}

void CusCheckBox::paintCheckBos(QPainter *painter)
{
    painter->restore();
    QRect rect( 0, 0, 50, 20 );
    painter->drawRect( rect );
    painter->fillRect( rect, Qt::green );
    painter->save();
}
