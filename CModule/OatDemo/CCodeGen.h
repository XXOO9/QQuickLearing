#ifndef CCODEGEN_H
#define CCODEGEN_H

#include <iostream>
#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/codegen/api_controller/base_define.hpp"
#include "CUserInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MyController : public oatpp::web::server::api::ApiController {
public:

    MyController(const std::shared_ptr<ObjectMapper>& objectMapper)
        : oatpp::web::server::api::ApiController(objectMapper)
    {
        std::cout << "mapper = " << objectMapper << std::endl;
    }

    static std::shared_ptr<MyController> createShared()
    {
        std::shared_ptr<ObjectMapper> objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        return std::make_shared<MyController>(objectMapper);
    }

    ENDPOINT( "POST", "/TEST1", root1, BODY_DTO( oatpp::Object<CUserInfo>, userInfo)) {
        auto user = CUserInfo::createShared();

        user->name = "name";
        auto type = userInfo->age.getValueType();
        OATPP_LOGI( "debug string:", "user name = %s, age = %d", userInfo->name->c_str(), *userInfo->age );
        auto response = createResponse(Status::CODE_200, "this is test");

        response->putHeader( Header::CONTENT_TYPE, "application/json;charset=UTF-8" );
        return response;

    }

    ENDPOINT("POST", "/TEST2", root2 )
    {
        auto user = CUserInfo::createShared();

        user->name = "name";
        return createResponse(Status::CODE_200, "this is test2");
    }

    ENDPOINT("POST", "/TEST3", root3, BODY_STRING(String, userInfo)) {
        std::cout << "str = " << *userInfo << std::endl;
        auto user = CUserInfo::createShared();

        user->name = "name";
        auto response = createResponse(Status::CODE_200, oatpp::String( "没毛病，老铁" ) );
        response->putHeader( Header::CONTENT_TYPE, "application/json;charset=UTF-8" );
        return response;
    }

private:
    void qioer();

    // TODO - more endpoints here

};

#include OATPP_CODEGEN_END(ApiController)

#endif // CCODEGEN_H
