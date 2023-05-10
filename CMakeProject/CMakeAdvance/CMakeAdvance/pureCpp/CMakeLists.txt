cmake_minimum_required( VERSION 3.14.0 )
project( PureCpp )

# set c++ standard version
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDRD_REQUIRED ON )


# group source files with group alias
set( mainSrc
     main.cpp
)

set( group1Files
     CGroup1.h   CGroup1.cpp
)

# note: group2 is stroed in subdirectory
set( group2Files
     group2/CGroup2.h    group2/CGroup2.cpp
)


# set group alias
source_group( group1Name FILES ${group1Files} )
source_group( main FILES ${mainSrc} )
source_group( group2Name FILES ${group2Files} )

# integration all group files
set( SRC_LIST
    ${mainSrc}
    ${group1Files}
    ${group2Files}
)

# generate executable file
add_executable( ${PROJECT_NAME} ${SRC_LIST} )
