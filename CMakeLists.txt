cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(gol VERSION 0.1.0)
add_definitions("-Wall" "-g")

set(SDL2_INCLUDE_DIR C:/SDL2/x86_64-w64-mingw32/include)
set(SDL2_LIB_DIR C:/SDL2/x86_64-w64-mingw32/lib)

set(SDL2_ttf_INCLUDE_DIR C:/SDL2/x86_64-w64-mingw32/include)
set(SDL2_ttf_LIB_DIR C:/SDL2/x86_64-w64-mingw32/lib)


include_directories(${SDL2_TTF_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_subdirectory(src)

add_executable(gol main.cpp)
target_link_libraries(gol program_files SDL2main SDL2 ${SDL2TTF_LIBRARIES})
target_include_directories(gol PUBLIC program_files)
add_definitions(-DSDL_MAIN_HANDLED)

#cmake_minimum_required(VERSION 3.1.0)
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#project(gol VERSION 0.1.0)
#add_definitions("-Wall" "-g")

#find_package( OpenGL REQUIRED )

#include_directories(${PROJECT_SOURCE_DIR})

#include_directories( ${OPENGL_INCLUDE_DIRS} )
#add_subdirectory(program_files)
#set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
#set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )


#file(GLOB_RECURSE SRC_FILES src/*.cpp) 
#add_executable(gol WIN32 main.cpp src/glad.c ${SRC_FILES})

#target_link_libraries( gol program_files ${OPENGL_LIBRARIES} glfw3)
#target_include_directories(gol PUBLIC ${CMAKE_SOURCE_DIR}/include PUBLIC program_files)



