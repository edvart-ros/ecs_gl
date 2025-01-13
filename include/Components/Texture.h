#pragma once
#include "Common.h"

struct Texture {
  unsigned int id;
  std::string path;
  Texture();
};

struct TextureMaps {
  Texture diffuse;
  Texture specular;
  Texture roughness;
  Texture emissive;
  Texture normal;
  Texture animation;
  TextureMaps();
};