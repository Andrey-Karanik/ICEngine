cmake_minimum_required(VERSION 3.0.0)
project(ICEngineEditor)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/../ICEngineCore/include)
find_package(OpenGL REQUIRED)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(ICEngineEditor ${SOURCES})
target_link_libraries(ICEngineEditor PRIVATE ICEngineCore ${PROJECT_SOURCE_DIR}/../ICEngineCore/lib/glfw3.lib OpenGL::GL)

add_custom_command(TARGET ICEngineEditor POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ICEngineCore> ${PROJECT_BINARY_DIR})