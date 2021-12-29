#ifndef CHTTPHEARTBEAT_H
#define CHTTPHEARTBEAT_H

#include <QObject>
#include "../CHttpAbstractNetWork/CHttpAbstractNetWork.h"
#include "../chttpmodule_global.h"

class CHTTPMODULESHARED_EXPORT CHttpHeartBeat : public CHttpAbstractNetWork
{
public:
    CHttpHeartBeat();
    virtual ~CHttpHeartBeat() override;

    virtual void initConfig() override;
    virtual void initConnection() override;
    virtual void httpRequest() override;
    virtual bool parseJson() override;
    virtual bool isParameterEmpty() override;

    void setStatus( devStatus status );
    void setBattery( QString battery );
    void setDevCode( QString devCode );
    void setDevType( QString devType );

public slots:
    virtual void onNewReplyAvailable( QNetworkReply *pReply ) override;
    virtual void onTimeoutHandler() override;
};

#endif // CHTTPHEARTBEAT_H
