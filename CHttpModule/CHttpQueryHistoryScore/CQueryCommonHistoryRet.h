#ifndef CQUERYCOMMONHISTORYRET_H
#define CQUERYCOMMONHISTORYRET_H

#include <QObject>
#include "../chttpmodule_global.h"
#include "../CHttpResult/CAbstractResult.h"

class CHTTPMODULESHARED_EXPORT CQueryCommonHistoryRet : public CAbstractResult
{
public:
    CQueryCommonHistoryRet();
    virtual ~CQueryCommonHistoryRet() override;
};

#endif // CQUERYCOMMONHISTORYRET_H
