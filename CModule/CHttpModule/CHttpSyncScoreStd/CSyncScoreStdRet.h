#ifndef CSYNCSCORESTDRET_H
#define CSYNCSCORESTDRET_H

#include <QObject>
#include "../CHttpResult/CAbstractResult.h"

namespace syncScoreStdKeys{
          const QString grade = "grade";
          const QString testItem = "testItem";
          const QString score = "score";
          const QString gender = "gender";
          const QString resultStart = "resultStart";
          const QString resultEnd = "resultEnd";
}

class CHTTPMODULESHARED_EXPORT CSyncScoreStdRet : public CAbstractResult
{
public:
    CSyncScoreStdRet();
    virtual ~CSyncScoreStdRet() override;
};

#endif // CSYNCSCORESTDRET_H
