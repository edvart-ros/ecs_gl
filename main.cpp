#include "Common.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Shader.h"
#include "Core/MeshImporter.h"
#include "Core/Primitives.h"
#include "Core/TextureManager.h"
#include "Core/Time.h"
#include "Core/Window.h"
#include "Input/Input.h"
#include "Rendering/Camera/Camera.h"
#include "Systems/Render.h"
#include "entt/src/entt/entt.hpp"

GLFWwindow *window = setupWindow(1200, 900);
float deltaTime = 0;
float previousTime = 0;
Mouse mouse = Mouse();
Keys keys = Keys();
TextureManager texMan;
Camera camera;

int main() {
  Shader shader("simple");
  Material material(shader);
  Mesh box = createBox();
  Mesh mesh = loadMesh("sphere.obj");
  Transform transform;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera.update(keys, mouse);

    Render(mesh, material, transform, camera);

    processInputs(window, keys);
    glfwSwapBuffers(window);
    glfwPollEvents();
    updateTime(deltaTime, previousTime);
  }
  glfwTerminate();
  return 0;
}