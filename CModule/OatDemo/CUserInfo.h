#ifndef CUSERINFO_H
#define CUSERINFO_H

#include <iostream>
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class CUserInfo : public oatpp::DTO
{
    DTO_INIT( CUserInfo, DTO );
    DTO_FIELD(String, name) = "default name";
    DTO_FIELD(Int32, age);

    void toString();
    void readFromString(oatpp::String jsStr);
};

#include OATPP_CODEGEN_END(DTO)

#endif // CUSERINFO_H
