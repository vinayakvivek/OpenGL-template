cmake_minimum_required(VERSION 2.8.9)
project(opengl_template)

add_compile_options(-std=c++11)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

set(target opengl_template)
add_executable(${target} ${SOURCES})

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
	message(STATUS "Found OpenGL")
	include_directories(${target} ${OPENGL_INCLUDE_DIR})
 	target_link_libraries(${target} ${OPENGL_gl_LIBRARY})
endif()

find_package(glfw3 REQUIRED)
target_link_libraries(${target} glfw)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
	message(STATUS "Found GLEW")
    include_directories(${target} ${GLEW_INCLUDE_DIRS})
    target_link_libraries(${target} ${GLEW_LIBRARIES})
endif()

# add_custom_command(TARGET ${target} POST_BUILD
#                    COMMAND ${CMAKE_COMMAND} -E copy_directory
#                    ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:${target}>/shaders)

add_custom_target(
        copy_shader_files
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/shaders
                       ${CMAKE_CURRENT_BINARY_DIR}/shaders
        COMMENT "Copying shader files for target: ${target}" VERBATIM
        )

add_dependencies(${target} copy_shader_files)