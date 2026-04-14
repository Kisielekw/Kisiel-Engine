cmake_minimum_required(VERSION 4.1)

project(Kisiel_Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

find_package(OpenGL REQUIRED)
find_package(glfw3 QUIET)

if (NOT glfw3_FOUND)
    message(STATUS "glfw3 was not found, downloading and building it...")

    fetchcontent_declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
    )
    fetchcontent_makeavailable(glfw)
endif()

find_package(glm QUIET)

if(NOT glm_FOUND)
    message(STATUS "glm was not found, downloading and building it...")

    fetchcontent_declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
    )
    fetchcontent_makeavailable(glm)
endif()

include_directories(include_Dependencies)

add_executable(Game src/main.cpp 
    src/Window.cpp
    src/Game.cpp
    src/Mesh.cpp
    src/Shader.cpp
    src/ResourceManager.cpp
    src/Camera.cpp
    src/Entity.cpp
    src/glad.c)
target_link_libraries(Game PRIVATE OpenGL::GL)
target_link_libraries(Game PRIVATE glfw)
target_link_libraries(Game PRIVATE glm)

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:Game>/Assets
)