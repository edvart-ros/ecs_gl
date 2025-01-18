#include "Scene.h"
#include "Logging/Logging.h"

Scene::Scene() {
  registry = entt::registry();
  auto mainChar = registry.create();
  Shader &vatShader = shaderMan.shader("vat");
  Material vatMaterial(vatShader);
  Mesh &characterMesh = meshMan.mesh("haz.glb");
  Movement characterMovement;
  Animation characterAnimation = Animation(69.0f, "haz.json");
  characterAnimation.subAnimations[0].startFrame = 0;
  characterAnimation.subAnimations[0].endFrame = 25;
  characterAnimation.subAnimations[1].startFrame = 26;
  characterAnimation.subAnimations[1].endFrame = 84;
  characterAnimation.subAnimations[2].startFrame = 86;
  characterAnimation.subAnimations[2].endFrame = 156;
  characterAnimation.animationIdx = 0;
  Transform tf;
  // tf.setScale(0.01f, 0.01f, 0.01f);
  vatMaterial.textures.animation = texMan.tex("hazOffsets.png");
  vatMaterial.textures.diffuse = texMan.tex("uvChecker.png");
  registry.emplace<Transform>(mainChar, tf);
  registry.emplace<Material>(mainChar, vatMaterial);
  registry.emplace<Mesh>(mainChar, characterMesh);
  registry.emplace<Animation>(mainChar, characterAnimation);
  registry.emplace<Movement>(mainChar, characterMovement);
  auto ground = registry.create();
  Shader &simpleShader = shaderMan.shader("grid");
  Material simpleMaterial(simpleShader);
  Mesh &planeMesh = meshMan.mesh("plane.obj");
  Transform groundTf;
  groundTf.setScale(1000.0f, 1.0f, 1000.0f);
  registry.emplace<Transform>(ground, groundTf);
  registry.emplace<Material>(ground, simpleMaterial);
  registry.emplace<Mesh>(ground, planeMesh);
}

void Scene::update() {
  auto movableView = registry.view<Movement, Transform, Animation>();
  for (auto entity : movableView) {
    auto &movement = movableView.get<Movement>(entity);
    auto &transform = movableView.get<Transform>(entity);
    auto &animation = registry.get<Animation>(entity);
    Move(movement, transform, animation);
  }
  this->render();
  return;
}

void Scene::Move(Movement &movement, Transform &transform,
                 Animation &animation) {
  glm::mat4 modelMat = transform.getLocalMat4();
  glm::vec3 fwdVec = glm::vec3(modelMat[0][2], modelMat[1][2], modelMat[2][2]);
  glm::vec3 leftVec = glm::vec3(modelMat[0][0], modelMat[1][0], modelMat[2][0]);
  glm::vec3 dir = glm::vec3(0.0f);
  if (keys.W) {
    dir += fwdVec;
  }
  if (keys.S) {
    dir -= fwdVec;
  }
  if (keys.A) {
    dir += leftVec;
  }
  if (keys.D) {
    dir -= leftVec;
  }
  if (glm::length(dir) > 0.001f) {
    dir = glm::normalize(dir);
    transform.position += dir * movement.linearSpeed * gTime.delta;
    animation.animationIdx = 0;
  } else {
    animation.animationIdx = 1;
  }
  camera.target = glm::mix(
      camera.target, transform.position + glm::vec3(0.0f, 1.0f, 0.0f), 0.05f);
  // camera.target = transform.position;
}

void Scene::render() {
  // render non-animatable
  auto renderableView =
      registry.view<Transform, Material, Mesh>(entt::exclude<Animation>);
  for (auto entity : renderableView) {

    auto &tf = renderableView.get<Transform>(entity);
    auto &mat = renderableView.get<Material>(entity);
    mat.shader.use();
    auto &mesh = renderableView.get<Mesh>(entity);
    RenderMesh(mesh, mat, tf, camera);
  }

  // render animatable objects
  auto animateView = registry.view<Transform, Material, Mesh, Animation>();
  for (auto entity : animateView) {
    auto &tf = animateView.get<Transform>(entity);
    auto &mat = animateView.get<Material>(entity);
    mat.shader.use();
    auto &mesh = animateView.get<Mesh>(entity);
    auto animation = animateView.get<Animation>(entity);
    const int i = animation.animationIdx;
    mat.shader.setFloat("time", gTime.current);
    mat.shader.setFloat("frameRate", animation.frameRate);
    mat.shader.setFloat("startFrame", animation.subAnimations[i].startFrame);
    mat.shader.setFloat("endFrame", animation.subAnimations[i].endFrame);
    mat.shader.setVec3("minBounds", animation.minBounds);
    mat.shader.setVec3("maxBounds", animation.maxBounds);

    RenderMesh(mesh, mat, tf, camera);
  }

  return;
}