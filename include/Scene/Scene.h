#pragma once
#include "Common.h"
#include "Components/Animation.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Movement.h"
#include "Components/Shader.h"
#include "Components/Transform.h"
#include "Core/MeshManager.h"
#include "Core/ShaderManager.h"
#include "Core/TextureManager.h"
#include "Core/Time.h"
#include "Logging/Logging.h"
#include "Rendering/Camera/Camera.h"
#include "Systems/Render.h"
#include "entt/src/entt/entity/fwd.hpp"
#include "entt/src/entt/entt.hpp"

struct Name {
  std::string name;
};

class Scene {
public:
  Scene();
  entt::registry registry;
  void update();
  void Move(Movement &movement, Transform &transform, Animation &animation);

private:
  void render();
};