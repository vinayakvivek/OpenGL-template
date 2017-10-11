cmake_minimum_required(VERSION 2.8.9)
project(opengl_template)

add_compile_options(-std=c++11)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(opengl_template ${SOURCES})

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
	message(STATUS "Found OpenGL")
	include_directories(opengl_template ${OPENGL_INCLUDE_DIR})
 	target_link_libraries(opengl_template ${OPENGL_gl_LIBRARY})
endif()

find_package(glfw3 REQUIRED)
target_link_libraries(opengl_template glfw)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
	message(STATUS "Found GLEW")
    include_directories(opengl_template ${GLEW_INCLUDE_DIRS})
    target_link_libraries(opengl_template ${GLEW_LIBRARIES})
endif()

add_custom_command(TARGET opengl_template PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:opengl_template>/shaders)