#include "CHttpPostHandle.h"

CHttpPostHandle::CHttpPostHandle()
{

}

CHttpPostHandle::~CHttpPostHandle()
{

}

std::shared_ptr<oatpp::web::server::HttpRequestHandler::OutgoingResponse> CHttpPostHandle::handle(const std::shared_ptr<IncomingRequest> &request)
{
    auto inputStream = request->getBodyStream();

    auto header = request->getBodyDecoder();


    auto &context = inputStream->getInputStreamContext();

    auto map = context.getProperties().getAll();
    return ResponseFactory::createResponse( Status::CODE_200, "WDNMD" );
}
