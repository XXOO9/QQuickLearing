#include "CUserInfo.h"
void CUserInfo::toString()
{
    auto tmpUserInfo = CUserInfo::createShared();
//    tmpUserInfo->name = "xtc";
    tmpUserInfo->age  = 26;

    auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

    oatpp::String jsStr = jsonObjectMapper->writeToString( tmpUserInfo );
    OATPP_LOGD( "json", "value='%s'", jsStr->c_str() );

    readFromString( jsStr );
}

void CUserInfo::readFromString( oatpp::String jsStr )
{
    auto jsMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

    auto jsObj = jsMapper->readFromString< oatpp::Object<CUserInfo> >( jsStr );
    std::cout << "name = " << jsObj->name->c_str() << std::endl;
}
