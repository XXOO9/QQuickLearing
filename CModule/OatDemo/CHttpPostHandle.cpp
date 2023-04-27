#include "CHttpPostHandle.h"

CHttpPostHandle::CHttpPostHandle()
{

}

CHttpPostHandle::~CHttpPostHandle()
{

}

std::shared_ptr<oatpp::web::server::HttpRequestHandler::OutgoingResponse> CHttpPostHandle::handle(const std::shared_ptr<IncomingRequest> &request)
{
//    auto objectMapper = oatpp::parser::json::mapping::ObjectMapper<CUserInfo>::createShared();
//    auto dto = request->readBodyToDto<CUserInfo>( objectMapper );

    return ResponseFactory::createResponse( Status::CODE_200, "WDNMD" );
}
