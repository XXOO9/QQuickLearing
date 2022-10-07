#ifndef CINTERACTION_H
#define CINTERACTION_H

#include <QObject>
#include <QDebug>

#include "CCameraControler.h"

class CInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CInterAction(QObject *parent = nullptr);
    virtual ~CInterAction() override;

private:
};

#endif // CINTERACTION_H
