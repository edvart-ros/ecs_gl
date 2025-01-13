#include "Scene.h"

Scene::Scene() {
  registry = entt::registry();
  Shader &shader = shaderMan.shader("vat");
  Material material(shader);
  Mesh &mesh = meshMan.mesh("cube.glb");
  Transform transform;
  auto mainCharacter = registry.create();
  material.textures.animation = texMan.tex("offsets.png");
  registry.emplace<Transform>(mainCharacter, transform);
  registry.emplace<Material>(mainCharacter, material);
  registry.emplace<Mesh>(mainCharacter, mesh);
  registry.emplace<Name>(mainCharacter, "mainCharacter");
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
    mat.shader.use();
    auto &mesh = renderableView.get<Mesh>(entity);
    mat.shader.setFloat("time", glfwGetTime());
    RenderMesh(mesh, mat, tf, camera);
  }
  return;
}
