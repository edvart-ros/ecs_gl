#include "Scene.h"

Scene::Scene() {
  registry = entt::registry();
  auto mainCharacter = registry.create();
  Shader &shader = shaderMan.shader("simple");
  Material material(shader);
  Mesh mesh = meshMan.mesh("cow.obj");
  Transform transform;
  material.textures.diffuse = texMan.tex("uvChecker.png");
  material.textures.specular = texMan.tex("backpackSpecular.jpg");
  registry.emplace<Transform>(mainCharacter, transform);
  registry.emplace<Material>(mainCharacter, material);
  registry.emplace<Mesh>(mainCharacter, mesh);
  registry.emplace<Name>(mainCharacter, "cow");
  camera.target = transform.position;
  for (int i = 0; i < 10; i++) {
    auto ball = registry.create();
    Shader &shader = shaderMan.shader("simple");
    Material material(shader);
    Mesh &mesh = meshMan.mesh("cube.obj");
    Transform transform;
    transform.position.y = -10 + i * 2;
    material.textures.diffuse = texMan.tex("uvChecker.png");
    material.textures.specular = texMan.tex("backpackSpecular.jpg");
    registry.emplace<Transform>(ball, transform);
    registry.emplace<Material>(ball, material);
    registry.emplace<Mesh>(ball, mesh);
  }
  for (int i = 0; i < 10; i++) {
    auto ball = registry.create();
    Shader &shader = shaderMan.shader("uv");
    Material material(shader);
    Mesh &mesh = meshMan.mesh("sphere.obj");
    Transform transform;
    transform.position.x = -10 + i * 2;
    material.textures.diffuse = texMan.tex("uvChecker.png");
    registry.emplace<Transform>(ball, transform);
    registry.emplace<Material>(ball, material);
    registry.emplace<Mesh>(ball, mesh);
  }
}

void Scene::update() {
  this->render();
  return;
}

void Scene::render() {
  auto renderableView = registry.view<Transform, Material, Mesh>();
  for (auto entity : renderableView) {
    auto &tf = renderableView.get<Transform>(entity);
    auto &mat = renderableView.get<Material>(entity);
    auto &mesh = renderableView.get<Mesh>(entity);
    tf.setRotation(glfwGetTime(), 0, 0);
    Render(mesh, mat, tf, camera);
  }
  auto namedView = registry.view<Name, Transform>();
  for (auto entity : namedView) {
    auto &name = namedView.get<Name>(entity);
    auto &tf = namedView.get<Transform>(entity);
    if (name.name == "cow") {
      auto time = glfwGetTime();
      tf.position.x = sin(time);
      tf.position.z = cos(time);
      tf.position.y = 0.3f * cos(time);
      camera.target = tf.position;
    }
  }
  return;
}
