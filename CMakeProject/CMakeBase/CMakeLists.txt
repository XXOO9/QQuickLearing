cmake_minimum_required( VERSION 3.20.0 )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )


add_compile_options(-fno-elide-constructors)
set(CMAKE_CXX_FLAGS "-fno-elide-constructors ${CMAKE_CXX_FLAGS}")

#编译平台判断
if( WIN32 )
    message( "Config as win32..." )
elseif( UNIX )
    message( "Config as unix..." )
endif()

project( CMakeBase )

#设置所有的源文件
set( SRC_LIST
    main.cpp
    CTester.h CTester.cpp
    CLambdaTest.h CLambdaTest.cpp
    CTestRValReference.h CTestRValReference.cpp
    Common.h
)

#添加子目录
add_subdirectory( StaticLib )
add_subdirectory( SharedLib )
add_subdirectory( SharedPointer )

#设置可执行程序生成路径
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/ )

#生成可执行程序
add_executable( ${PROJECT_NAME} ${SRC_LIST} )

message( "main project path = " ${CMAKE_CURRENT_SOURCE_DIR} )

#链接外部库
target_link_libraries( ${PROJECT_NAME} LibDemoStatic )
target_link_libraries( ${PROJECT_NAME} LibDemoShared )
target_link_libraries( ${PROJECT_NAME} LibDemoSharedPointer )
