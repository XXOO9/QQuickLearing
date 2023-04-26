#include <QDebug>
#include "CHttpGetHandler.h"
#include "CHttpPostHandle.h"

/**
 * Custom Request Handler
 */
class Handler : public oatpp::web::server::HttpRequestHandler {
public:

    /**
   * Handle incoming request and return outgoing response.
   */
    virtual std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override
    {
        return ResponseFactory::createResponse(Status::CODE_200, "Hello World!");
    }

};

void run() {

    /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();

    /* Route GET - "/hello" requests to Handler */
    router->route("GET", "/WDNMD", std::make_shared<CHttpGetHandler>());

    router->route("POST", "/NMSL", std::make_shared<CHttpPostHandle>());

    /* Create HTTP connection handler with router */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    /* Create TCP connection provider */
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"localhost", 8000, oatpp::network::Address::IP_4});

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Priny info about server port */
    OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

    /* Run server */
    server.run();
}

int main() {

    /* Init oatpp Environment */
    oatpp::base::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();

    return 0;

}
