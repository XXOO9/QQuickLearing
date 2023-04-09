cmake_minimum_required( VERSION 3.26.0 )
project( LibDemoShared )


message( shared CMakeLists path = ./)
include_directories( . )
aux_source_directory( . SRC_LIST )

add_library( ${PROJECT_NAME} SHARED ${SRC_LIST} )