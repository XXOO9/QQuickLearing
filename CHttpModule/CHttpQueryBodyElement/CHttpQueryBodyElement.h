﻿#ifndef CHTTPQUERYBODYELEMENT_H
#define CHTTPQUERYBODYELEMENT_H

#include <QObject>
#include "../CHttpAbstractNetWork/CHttpAbstractNetWork.h"
#include "../chttpmodule_global.h"

class CHttpQueryBodyElement : public CHttpAbstractNetWork
{
public:
    CHttpQueryBodyElement();
    virtual ~CHttpQueryBodyElement() override;

    virtual void initConfig() override;
    virtual void initConnection() override;
    virtual void httpRequest() override;
    virtual bool parseJson() override;
    virtual bool isParameterEmpty() override;

    void setUserId( QString userId );
    void setTimeInterval( queryTimeInterval timeinterval );
    void setQueryDevType( QString devType );

public slots:
    virtual void onNewReplyAvailable( QNetworkReply *pReply ) override;
    virtual void onTimeoutHandler() override;
};

#endif // CHTTPQUERYBODYELEMENT_H
