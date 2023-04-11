cmake_minimum_required( VERSION 3.22.0 )
project( LibDemoShared )

message( "current cmake path = " ${CMAKE_CURRENT_BINARY_DIR})

set( TARGET_BIN_PATH  ${CMAKE_CURRENT_BINARY_DIR}/../bin/ )
message( "target build path = " ${TARGET_BIN_PATH} )

if( WIN32 )
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