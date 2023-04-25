﻿#ifndef CSERVER_H
#define CSERVER_H

#include "./oatpp/web/server/api/ApiController.hpp"
#include "./oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MyController : public oatpp::web::server::api::ApiController {
public:

  MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) /* Inject object mapper */)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}

  ENDPOINT("GET", "/", root) {
    return createResponse(Status::CODE_200, "Hello World!");
  }

  // TODO - more endpoints here

};

#include OATPP_CODEGEN_END(ApiController)

#endif // CSERVER_H
