#pragma once
#include "Components/Shader.h"
#include "Components/Texture.h"

struct Material {
  Shader &shader;
  TextureMaps textures;
  Material(Shader &shader);
};