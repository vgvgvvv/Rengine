PROJECT(Rengine)

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -D_GLIBCXX_USE_NANOSLEEP -g ")
set(CMAKE_CXX_STANDARD  11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(OpenGL REQUIRED)
find_package(Assimp REQUIRED)

INCLUDE_DIRECTORIES(Source/Common)
INCLUDE_DIRECTORIES(Source/GameSystem)
INCLUDE_DIRECTORIES(Source/Renderer)

INCLUDE_DIRECTORIES(
        Include/Common/)

LINK_DIRECTORIES(Libs/MACOS/)


file(GLOB_RECURSE include_script
        Include/Common/*.hpp
        Include/Common/*.h )

#游戏系统部分
file(GLOB_RECURSE game_system_script
        Source/GameSystem/*.cpp
        Source/GameSystem/*.hpp
        Source/GameSystem/*.h)

#C++常用函数
file(GLOB_RECURSE common_script
        Source/Common/*.cpp
        Source/Common/*.hpp
        Source/Common/*.h)

#渲染部分
file(GLOB_RECURSE renderer_script
        Source/Renderer/*.cpp
        Source/Renderer/*.hpp
        Source/Renderer/*.h)


set(all_source
        ${include_script}
        ${game_system_script}
        ${common_script}
        ${renderer_script}
        Source/Main.cpp)


set(all_lib
        ${OPENGL_LIBRARY}
        glew
        glfw
        STB
        Assimp)

add_executable(ReEngine ${all_source})
target_link_libraries(ReEngine ${all_lib})
