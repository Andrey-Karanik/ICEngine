cmake_minimum_required(VERSION 3.0.0)
project(mya)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/../mylibrary/include)
find_package(OpenGL REQUIRED)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(mya ${SOURCES})
target_link_libraries(mya PRIVATE mylib ${PROJECT_SOURCE_DIR}/../mylibrary/lib/glfw3.lib OpenGL::GL)

add_custom_command(TARGET mya POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:mylib> ${PROJECT_BINARY_DIR})