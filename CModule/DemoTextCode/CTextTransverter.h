#ifndef CTEXTTRANSVERTER_H
#define CTEXTTRANSVERTER_H

#include <QDebug>
#include <QString>
#include <QObject>
#include <QImage>
#include <QSize>
#include <QPainter>
#include <QPen>
#include <QFont>
#include <QMatrix>
#include <QCoreApplication>

class CTextTransverter
{
public:
    CTextTransverter();

    QImage createImg( QByteArray text );

    static unsigned short *getArray(QImage &img );

    static void display( unsigned short *ptr );

private:
    void loadCusFont();



    QString m_fontRealName;
};

#endif // CTEXTTRANSVERTER_H
