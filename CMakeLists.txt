cmake_minimum_required(VERSION 3.0)

PROJECT(Rengine)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(Include/Common)
LINK_DIRECTORIES(Libs/MACOS)

ADD_SUBDIRECTORY(Source)