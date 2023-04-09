project( LibDemoStatic )

set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set( SRC_LIST
    TestStaticLib.h TestStaticLib.cpp
)

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/ )

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST} )
