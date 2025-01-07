cmake_minimum_required(VERSION 3.16)
project(LearningOpenGL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES
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

# Link libraries
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
set(CMAKE_PREFIX_PATH "/usr/local/lib/cmake/assimp-5.4" ${CMAKE_PREFIX_PATH})

find_package(ASSIMP REQUIRED)

target_link_libraries(main PRIVATE
    ${OPENGL_gl_LIBRARY}
    GLEW::GLEW
    glfw
    /usr/local/lib/libassimp.dylib
)


include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)
