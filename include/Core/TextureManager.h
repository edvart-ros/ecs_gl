#pragma once
#include "Common.h"
#include "Components/Texture.h"
#include "Core/Path.h"
#include <unordered_map>

class TextureManager {
public:
  TextureManager();
  Texture &tex(const std::string &name);
  static Texture CreateTex2D(const std::string &path);

private:
  std::unordered_map<std::string, Texture> textures;
};