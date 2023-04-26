#ifndef CHTTPGETHANDLER_H
#define CHTTPGETHANDLER_H

#include <QDebug>
#include <memory>

#include "oatpp/network/Server.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/protocol/http/incoming/Request.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

using namespace oatpp::web::protocol::http::incoming;
using namespace std;

class CHttpGetHandler : public oatpp::web::server::HttpRequestHandler
{
public:
    CHttpGetHandler();

    virtual ~CHttpGetHandler();

    virtual std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override;
};

#endif // CHTTPGETHANDLER_H
