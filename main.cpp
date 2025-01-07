#include "Common.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Shader.h"
#include "Core/Path.h"
#include "Core/Primitives.h"
#include "Core/TextureManager.h"
#include "Core/Time.h"
#include "Core/Window.h"
#include "Input/Input.h"
#include "Logging/Logging.h"
#include "Rendering/camera/Camera.h"
#include "Systems/Render.h"

GLFWwindow *window = setupWindow(1200, 900);
float deltaTime = 0;
float previousTime = 0;
Mouse mouse = Mouse();
Keys keys = Keys();
TextureManager texMan;

int main() {
  Camera camera;
  Shader shader("simple");
  Material material(shader);
  Mesh box = createBox();
  material.textures.diffuse = texMan.tex("backpackDiffuse.jpg");
  material.textures.normal = texMan.tex("backpackNormal.png");
  material.textures.specular = texMan.tex("backpackSpecular.jpg");
  std::cout << material.textures.diffuse.id << std::endl;
  std::cout << material.textures.normal.id << std::endl;
  std::cout << material.textures.specular.id << std::endl;

  int n = 10;
  glm::vec3 start = -glm::vec3((n - 2) * 3.0f, 0.0f, (n - 2) * 3.0f) / 2.0f;
  Transform transforms[n * n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      Transform tf;
      tf.position.x = start.x + i * 3.0f;
      tf.position.z = start.z + j * 3.0f;
      transforms[i * n + j] = tf;
    }
  }

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera.update(keys, mouse);
    material.shader.use();
    material.shader.setMat4("view", camera.viewMatrix);
    material.shader.setMat4("projection", camera.projectionMatrix);
    RenderBatch(box, material, transforms, n * n);

    processInputs(window, keys);
    glfwSwapBuffers(window);
    glfwPollEvents();
    updateTime(deltaTime, previousTime);
  }
  glfwTerminate();
  return 0;
}