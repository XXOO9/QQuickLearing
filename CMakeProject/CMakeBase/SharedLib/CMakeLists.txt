﻿cmake_minimum_required( VERSION 3.22.0 )
project( LibDemoShared )

message( "current cmake path = " ${CMAKE_CURRENT_BINARY_DIR})

#预编译宏 -DXXXX
ADD_DEFINITIONS( -DLIBRYARYEXPORT )

set( TARGET_BIN_PATH  ${CMAKE_CURRENT_BINARY_DIR}/../bin/ )
message( "target build path = " ${TARGET_BIN_PATH} )

if( WIN32 )
    #设置生成路径，注意：生成动态库的标志和生成可执行程序的关键字不一样
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${TARGET_BIN_PATH} )
    message( "custom shared library output on windows as .dll" )
elseif( UNIX )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${TARGET_BIN_PATH} )
    message( "custom shared library output on windows as .so ")
endif()

set( SRC_LIST
     TestSharedLib.h TestSharedLib.cpp
)

add_library( ${PROJECT_NAME} SHARED ${SRC_LIST} )
