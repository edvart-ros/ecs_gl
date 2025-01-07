#include "Primitives.h"

Mesh createBox() {
  std::vector<Vertex> vertices(24);

  vertices[0].position = glm::vec3(-1.0f, -1.0f, -1.0f);
  vertices[1].position = glm::vec3(1.0f, -1.0f, -1.0f);
  vertices[2].position = glm::vec3(1.0f, 1.0f, -1.0f);
  vertices[3].position = glm::vec3(-1.0f, 1.0f, -1.0f);
  vertices[0].uv = glm::vec2(0.0f, 0.0f);
  vertices[1].uv = glm::vec2(1.0f, 0.0f);
  vertices[2].uv = glm::vec2(1.0f, 1.0f);
  vertices[3].uv = glm::vec2(0.0f, 1.0f);
  vertices[4].position = glm::vec3(-1.0f, -1.0f, 1.0f);
  vertices[5].position = glm::vec3(-1.0f, 1.0f, 1.0f);
  vertices[6].position = glm::vec3(1.0f, 1.0f, 1.0f);
  vertices[7].position = glm::vec3(1.0f, -1.0f, 1.0f);
  vertices[4].uv = glm::vec2(0.0f, 0.0f);
  vertices[5].uv = glm::vec2(1.0f, 0.0f);
  vertices[6].uv = glm::vec2(1.0f, 1.0f);
  vertices[7].uv = glm::vec2(0.0f, 1.0f);
  vertices[8].position = glm::vec3(-1.0f, -1.0f, 1.0f);
  vertices[9].position = glm::vec3(-1.0f, -1.0f, -1.0f);
  vertices[10].position = glm::vec3(-1.0f, 1.0f, -1.0f);
  vertices[11].position = glm::vec3(-1.0f, 1.0f, 1.0f);
  vertices[8].uv = glm::vec2(0.0f, 0.0f);
  vertices[9].uv = glm::vec2(1.0f, 0.0f);
  vertices[10].uv = glm::vec2(1.0f, 1.0f);
  vertices[11].uv = glm::vec2(0.0f, 1.0f);
  vertices[12].position = glm::vec3(1.0f, -1.0f, 1.0f);
  vertices[13].position = glm::vec3(1.0f, 1.0f, 1.0f);
  vertices[14].position = glm::vec3(1.0f, 1.0f, -1.0f);
  vertices[15].position = glm::vec3(1.0f, -1.0f, -1.0f);
  vertices[12].uv = glm::vec2(0.0f, 0.0f);
  vertices[13].uv = glm::vec2(1.0f, 0.0f);
  vertices[14].uv = glm::vec2(1.0f, 1.0f);
  vertices[15].uv = glm::vec2(0.0f, 1.0f);
  vertices[16].position = glm::vec3(-1.0f, 1.0f, -1.0f);
  vertices[17].position = glm::vec3(1.0f, 1.0f, -1.0f);
  vertices[18].position = glm::vec3(1.0f, 1.0f, 1.0f);
  vertices[19].position = glm::vec3(-1.0f, 1.0f, 1.0f);
  vertices[16].uv = glm::vec2(0.0f, 0.0f);
  vertices[17].uv = glm::vec2(1.0f, 0.0f);
  vertices[18].uv = glm::vec2(1.0f, 1.0f);
  vertices[19].uv = glm::vec2(0.0f, 1.0f);

  vertices[20].position = glm::vec3(-1.0f, -1.0f, -1.0f);
  vertices[21].position = glm::vec3(-1.0f, -1.0f, 1.0f);
  vertices[22].position = glm::vec3(1.0f, -1.0f, 1.0f);
  vertices[23].position = glm::vec3(1.0f, -1.0f, -1.0f);
  vertices[20].uv = glm::vec2(0.0f, 0.0f);
  vertices[21].uv = glm::vec2(1.0f, 0.0f);
  vertices[22].uv = glm::vec2(1.0f, 1.0f);
  vertices[23].uv = glm::vec2(0.0f, 1.0f);

  glm::vec3 normals[6] = {
      glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
      glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
      glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec3(0.0f, -1.0f, 0.0f)};

  for (int i = 0; i < 6; i++) {
    vertices[i * 4].normal = normals[i];
    vertices[i * 4 + 1].normal = normals[i];
    vertices[i * 4 + 2].normal = normals[i];
    vertices[i * 4 + 3].normal = normals[i];
  }

  std::vector<unsigned int> indices = {
      0,  1,  2,  2,  3,  0,  4,  5,  6,  6,  7,  4,  8,  9,  10, 10, 11, 8,
      12, 13, 14, 14, 15, 12, 16, 17, 18, 18, 19, 16, 20, 21, 22, 22, 23, 20};

  return Mesh(vertices, indices);
}
