#include "Scene.h"

Scene::Scene() {
  registry = entt::registry();
  for (int i = 0; i < 10; i++) {
    auto ball = registry.create();
    Shader &shader = shaderMan.shader("simple");
    Material material(shader);
    Mesh mesh = meshMan.mesh("sphere.obj");
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
    Mesh mesh = meshMan.mesh("sphere.obj");
    Transform transform;
    transform.position.x = -10 + i * 2;
    material.textures.diffuse = texMan.tex("uvChecker.png");
    registry.emplace<Transform>(ball, transform);
    registry.emplace<Material>(ball, material);
    registry.emplace<Mesh>(ball, mesh);
  }
}

void Scene::RenderScene() {
  auto renderableView = registry.view<Transform, Material, Mesh>();
  for (auto entity : renderableView) {
    auto &tf = renderableView.get<Transform>(entity);
    auto &mat = renderableView.get<Material>(entity);
    auto &mesh = renderableView.get<Mesh>(entity);
    Render(mesh, mat, tf, camera);
  }
  return;
}
