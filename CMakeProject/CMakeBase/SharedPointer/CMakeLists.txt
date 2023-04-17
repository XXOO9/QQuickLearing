cmake_minimum_required( VERSION 3.20.0 )
set( CMAKE_CXX_STANDARD 11 )
project( LibDemoSharedPointer )

if( WIN32 )
    add_definitions( -DLIBRARYEXPORT )
endif()

set( SRC_LIST
     SharedPointerGlobal.h
     Boy.h Boy.cpp
     Girl.h Girl.cpp
     CTestCycleRefrence.h CTestCycleRefrence.cpp
)

set( TARGETPATH ${CMAKE_CURRENT_BINARY_DIR}/../bin/ )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGETPATH} )
add_library( ${PROJECT_NAME} SHARED ${SRC_LIST} )
