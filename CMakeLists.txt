PROJECT(Rengine)

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -D_GLIBCXX_USE_NANOSLEEP -g ")
set(CMAKE_CXX_STANDARD  11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(Source/Common)
INCLUDE_DIRECTORIES(Source/GameSystem)
INCLUDE_DIRECTORIES(Source/Renderer)

INCLUDE_DIRECTORIES(
        Include/Common/)

LINK_DIRECTORIES(Libs/MACOS/)


file(GLOB_RECURSE include_script
        Include/Common/*.hpp
        Include/Common/*.h )

file(GLOB_RECURSE game_system_script
        Source/GameSystem/*.cpp
        Source/GameSystem/*.hpp)

file(GLOB_RECURSE common_script
        Source/Common/*.cpp
        Source/Common/*.hpp)

file(GLOB_RECURSE renderer_script
        Source/Renderer/*.cpp
        Source/Renderer/*.hpp)


set(all_source
        ${include_script}
        ${game_system_script}
        ${common_script}
        ${renderer_script}
        Source/Main.cpp)


set(all_lib
        ${OPENGL_LIBRARY}
        ${CMAKE_DL_LIBS}
        glew
        glfw
        STB
        Assimp)

add_executable(ReEngine ${all_source})
target_link_libraries(ReEngine ${all_lib})
