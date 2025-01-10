#pragma once
#include "Common.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Shader.h"
#include "Components/Transform.h"
#include "Core/MeshManager.h"
#include "Core/ShaderManager.h"
#include "Core/TextureManager.h"
#include "Rendering/Camera/Camera.h"
#include "Systems/Render.h"
#include "entt/src/entt/entity/fwd.hpp"
#include "entt/src/entt/entt.hpp"

class Scene {
public:
  Scene();
  entt::registry registry;
  void RenderScene();

private:
};