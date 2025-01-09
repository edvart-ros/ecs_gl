cmake_minimum_required(VERSION 3.16)
project(LearningOpenGL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)


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

add_executable(main ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(ZLIB REQUIRED)

target_link_libraries(main 
    ${OPENGL_gl_LIBRARY}
    glfw3
    glew
    assimp
    ZLIB::ZLIB
)

target_link_libraries(main "-framework Cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreFoundation" "-framework CoreGraphics")