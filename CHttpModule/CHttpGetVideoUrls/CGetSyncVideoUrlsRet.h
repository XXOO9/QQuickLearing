#ifndef CGETSYNCVIDEOURLSRET_H
#define CGETSYNCVIDEOURLSRET_H

#include <QObject>
#include "../CHttpResult/CAbstractResult.h"

class CGetSyncVideoUrlsRet : public CAbstractResult
{
public:
    CGetSyncVideoUrlsRet();
    virtual ~CGetSyncVideoUrlsRet() override;
};

#endif // CGETSYNCVIDEOURLSRET_H
