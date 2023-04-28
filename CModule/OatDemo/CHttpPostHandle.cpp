#include "CHttpPostHandle.h"

CHttpPostHandle::CHttpPostHandle()
{

}

CHttpPostHandle::~CHttpPostHandle()
{

}

std::shared_ptr<oatpp::web::server::HttpRequestHandler::OutgoingResponse> CHttpPostHandle::handle(const std::shared_ptr<IncomingRequest> &request)
{

    auto bodyDecoder = request->getBodyDecoder();

    auto headers = request->getHeaders();

    auto bodyStream = request->getBodyStream();

    auto connection = request->getConnection();

    String str = bodyDecoder->decodeToString( headers, bodyStream.get(), connection.get() );

    std::shared_ptr<oatpp::parser::json::mapping::ObjectMapper> jsMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

    oatpp::Object<CUserInfo> userInfo = jsMapper->readFromString< oatpp::Object<CUserInfo> >( str );

    return ResponseFactory::createResponse( Status::CODE_200, "WDNMD" );
}
