#ifndef CABSTRACTINTERACTION_H
#define CABSTRACTINTERACTION_H

#include <QObject>

class CAbstractInterAction : public QObject
{
    Q_OBJECT
public:
    explicit CAbstractInterAction(QObject *parent = nullptr);
    virtual ~CAbstractInterAction() override;

signals:

public slots:
};

#endif // CABSTRACTINTERACTION_H
