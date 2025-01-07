#pragma once
#include "Common.h"

struct Transform {
  glm::vec3 position;
  glm::vec3 scale;
  glm::quat rotation;
  Transform();
  glm::mat4 getLocalMat4() const;
  void setScale(float x, float y, float z);
  void setRotation(float x, float y, float z);
};