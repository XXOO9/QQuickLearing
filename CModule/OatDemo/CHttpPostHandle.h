#ifndef CHTTPPOSTHANDLE_H
#define CHTTPPOSTHANDLE_H

#include <QDebug>
#include <memory>

#include "oatpp/network/Server.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/protocol/http/incoming/Request.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/api/ApiController.hpp"

#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/codegen/api_controller/base_define.hpp"

#include "oatpp/core/data/mapping/ObjectMapper.hpp"
#include "oatpp/core/base/ObjectHandle.hpp"

#include "CUserInfo.h"

using namespace oatpp;

class CHttpPostHandle : public oatpp::web::server::HttpRequestHandler
{
public:
    CHttpPostHandle();
    virtual ~CHttpPostHandle();

    virtual std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;
};

#endif // CHTTPPOSTHANDLE_H
