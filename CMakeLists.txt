cmake_minimum_required(VERSION 3.16)
project(LearningOpenGL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(ASSIMP_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF CACHE BOOL "" FORCE)
set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)
set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)

set(ASSIMP_BUILD_OBJ_IMPORTER ON CACHE BOOL "" FORCE)

add_subdirectory(third-party/assimp)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/include/Components/Vertex.cpp
    ${CMAKE_SOURCE_DIR}/include/Defines.cpp
    ${CMAKE_SOURCE_DIR}/include/Core/Window.cpp
    ${CMAKE_SOURCE_DIR}/include/Core/Time.cpp
    ${CMAKE_SOURCE_DIR}/include/Core/Path.cpp
    ${CMAKE_SOURCE_DIR}/include/Core/MeshImporter.cpp
    ${CMAKE_SOURCE_DIR}/include/Logging/Logging.cpp
    ${CMAKE_SOURCE_DIR}/include/Core/Primitives.cpp
    ${CMAKE_SOURCE_DIR}/include/Core/TextureManager.cpp
    ${CMAKE_SOURCE_DIR}/include/Components/Shader.cpp
    ${CMAKE_SOURCE_DIR}/include/Components/Mesh.cpp
    ${CMAKE_SOURCE_DIR}/include/Components/Material.cpp
    ${CMAKE_SOURCE_DIR}/include/Components/Texture.cpp
    ${CMAKE_SOURCE_DIR}/include/Components/Transform.cpp
    ${CMAKE_SOURCE_DIR}/include/Systems/Render.cpp
    ${CMAKE_SOURCE_DIR}/include/Math/Geometry.cpp
    ${CMAKE_SOURCE_DIR}/include/Input/Input.cpp
    ${CMAKE_SOURCE_DIR}/include/Rendering/Camera/Camera.cpp
)

# Add the executable
add_executable(main ${SOURCES})

# Find required packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(main PRIVATE
    ${OPENGL_gl_LIBRARY}
    GLEW::GLEW
    glfw
    assimp::assimp
)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)
