#include "Common.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Shader.h"
#include "Core/MeshImporter.h"
#include "Core/MeshManager.h"
#include "Core/Primitives.h"
#include "Core/ShaderManager.h"
#include "Core/TextureManager.h"
#include "Core/Time.h"
#include "Core/Window.h"
#include "Input/Input.h"
#include "Rendering/Camera/Camera.h"
#include "Scene/Scene.h"
#include "Systems/Render.h"
#include "entt/src/entt/entt.hpp"
#include <CoreServices/CoreServices.h>
#include <filesystem>
#include <thread>

GLFWwindow *window = setupWindow(1920, 900);
Time gTime;
Mouse mouse = Mouse();
Keys keys = Keys();
TextureManager texMan;
ShaderManager shaderMan;
MeshManager meshMan;
Camera camera;

int main() {
  Scene scene;
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwPollEvents();
    processInputs(window, keys);
    gTime.update();

    camera.update(keys, mouse);
    shaderMan.hotReload();
    scene.update();

    glfwSwapBuffers(window);
    mouse.resetDelta();
  }
  glfwTerminate();
  return 0;
}