cmake_minimum_required( VERSION 3.6.2 )

# For a new project it is sufficient to change only its name in the following line
set( PROJECT_NAME AircraftShooter  )

project( ${PROJECT_NAME} )

set( CMAKE_BUILD_TYPE Debug )
#set( CMAKE_BUILD_TYPE Release )

#set required version of C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_XXX_STANDARD REQUIRED True)

if( WIN32 )
	set( CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /GR /EHsc /std:c++17 /D_UNICODE /DUNICODE" )
	set( CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1 /std:c++17 /D_UNICODE /DUNICODE" )
	message( "Win settings chosen..." )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" )
	set( CMAKE_CXX_FLAGS "-std=c++17 -Wall" )
	set( CMAKE_CXX_FLAGS_DEBUG "-g -std=c++17 -Wall" )
	message( "Mac settings chosen..." )
elseif( UNIX )
	set( CMAKE_CXX_FLAGS "-std=c++17 -Wall" )
	set( CMAKE_CXX_FLAGS_DEBUG "-g -std=c++17 -Wall" )
	message( "Linux settings chosen..." )
endif()

#Find additional libraries
find_package(SDL2 REQUIRED PATHS "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/cmake")
find_package(SDL2_image REQUIRED PATHS "${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2_image-2.6.2/cmake")

# Inform CMake where the header files are
include_directories( include )
include_directories( "${SDL2_INCLUDE_DIR}")
include_directories( lib/SDL2_image-2.6.2/include ) 


# Automatically add all *.cpp and *.h files to the project
file ( GLOB SOURCES "./source/*.cpp" "./include/*.h" "./lib/SDL2/include/*.h"
		"lib/SDL2_image-2.6.2/include/*.h")

add_executable( ${PROJECT_NAME} ${SOURCES} )

#Link libraries to the target
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2_image-2.6.2/lib/x64/SDL2_image.lib) 

#Copy .dll files to the output directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/lib/x64/SDL2.dll DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE} )
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2_image-2.6.2/lib/x64/SDL2_image.dll DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE} )

# Set the default project 
set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )


message( "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}" )