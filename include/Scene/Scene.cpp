#include "Scene.h"

Scene::Scene() {
  registry = entt::registry();
  Shader &vatShader = shaderMan.shader("vat");
  Material vatMaterial(vatShader);
  Mesh &characterMesh = meshMan.mesh("Character.glb");
  auto mainChar = registry.create();
  vatMaterial.textures.animation = texMan.tex("offsets.png");
  vatMaterial.textures.diffuse = texMan.tex("albedo.png");
  registry.emplace<Transform>(mainChar);
  registry.emplace<Material>(mainChar, vatMaterial);
  registry.emplace<Mesh>(mainChar, characterMesh);
  registry.emplace<Name>(mainChar, "mainCharacter");

  Shader &simpleShader = shaderMan.shader("grid");
  Material simpleMaterial(simpleShader);
  Mesh &planeMesh = meshMan.mesh("plane.obj");
  Transform groundTf;
  groundTf.setScale(1000.0f, 1.0f, 1000.0f);
  auto ground = registry.create();
  registry.emplace<Transform>(ground, groundTf);
  registry.emplace<Material>(ground, simpleMaterial);
  registry.emplace<Mesh>(ground, planeMesh);
  registry.emplace<Name>(ground, "ground");
}

void Scene::update() {
  this->render();
  return;
}

void Scene::render() {
  auto renderableView = registry.view<Transform, Material, Mesh, Name>();
  for (auto entity : renderableView) {
    auto &tf = renderableView.get<Transform>(entity);
    auto &mat = renderableView.get<Material>(entity);
    mat.shader.use();
    auto &mesh = renderableView.get<Mesh>(entity);
    auto &name = renderableView.get<Name>(entity);
    mat.shader.setFloat("time", glfwGetTime());
    std::cout << name.name << std::endl;
    RenderMesh(mesh, mat, tf, camera);
  }
  return;
}
