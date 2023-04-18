cmake_minimum_required( VERSION 3.20.0 )

set( CMAKE_CXX_STANDARD 11 )

project( LibMultiThread )

if( WIN32 )
    add_definitions( -DLIBRARYEXPORT )
    message( "build multi thread library as .dll" )
elseif( UNIX )
    message( "build thread library as .so" )
endif()


set( TARGETPATH ${CMAKE_CURRENT_BINARY_DIR}/../bin/ )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGETPATH} )

message( "thread build path = " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )

set( SRC_LIST
    MultiThread_Global.h
    CThread.h CThread.cpp
)

add_library( ${PROJECT_NAME} SHARED ${SRC_LIST} )
