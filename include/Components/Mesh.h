#pragma once

#include "Common.h"
#include "Shader.h"
#include "Texture.h"
#include "Vertex.h"

struct Mesh {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  unsigned int VAO, VBO, EBO;

  Mesh(std::vector<Vertex>, std::vector<unsigned int> indices);
};
