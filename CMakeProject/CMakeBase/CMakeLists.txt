cmake_minimum_required( VERSION 3.26.0 )

project( CMakeBase )

set( SRC_LIST
    main.cpp
    CTester.h CTester.cpp
)

add_subdirectory( StaticLib )
add_subdirectory( SharedLib )

add_executable( ${PROJECT_NAME} ${SRC_LIST} )

target_link_libraries( ${PROJECT_NAME} LibDemoStatic )
target_link_libraries( ${PROJECT_NAME} LibDemoShared )
