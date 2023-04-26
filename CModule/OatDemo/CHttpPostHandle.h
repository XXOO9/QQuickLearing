#ifndef CHTTPPOSTHANDLE_H
#define CHTTPPOSTHANDLE_H

#include <QDebug>
#include <memory>

#include "oatpp/network/Server.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/protocol/http/incoming/Request.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

class CHttpPostHandle : public oatpp::web::server::HttpRequestHandler
{
public:
    CHttpPostHandle();
    virtual ~CHttpPostHandle();

    virtual std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;
};

#endif // CHTTPPOSTHANDLE_H
