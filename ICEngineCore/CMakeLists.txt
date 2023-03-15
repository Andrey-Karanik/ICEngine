cmake_minimum_required(VERSION 3.0.0)
project(ICEngineCore)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/engine.cpp)

add_library(ICEngineCore STATIC ${SOURCES})
target_link_libraries(ICEngineCore PRIVATE ${PROJECT_SOURCE_DIR}/lib/glfw3.lib)