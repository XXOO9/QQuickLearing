#ifndef CDATABASEOPERATION_H
#define CDATABASEOPERATION_H

#include <QObject>

class CDataBaseOperation : public QObject
{
    Q_OBJECT
public:
    explicit CDataBaseOperation(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CDATABASEOPERATION_H
