#include "CHttpGetHandler.h"

CHttpGetHandler::CHttpGetHandler()
{

}

CHttpGetHandler::~CHttpGetHandler()
{

}

std::shared_ptr<oatpp::web::server::HttpRequestHandler::OutgoingResponse>
CHttpGetHandler::handle(const std::shared_ptr<oatpp::web::server::HttpRequestHandler::IncomingRequest> &request)
{
    std::map<int, std::string> tmpMap = { {1,"WDNMD"} };

    auto parameters = request->getQueryParameters();

    auto ret = request->getQueryParameter( "key1" );
    qDebug() << QString::fromStdString( *ret );

    return ResponseFactory::createResponse( Status::CODE_200, ret );
}
