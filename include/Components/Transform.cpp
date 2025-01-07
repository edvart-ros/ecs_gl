#include "Transform.h"

Transform::Transform()
    : position(0.0f), scale(1.0f), rotation(1.0f, 0.0f, 0.0f, 0.0f) {}

void Transform::setScale(float x, float y, float z) {
  if ((x == 0) || (y == 0) || (z == 0)) {
    printf("WARNING: ignoring scale with zero-component \n");
    return;
  };
  this->scale = glm::vec3(x, y, z);
}

glm::mat4 Transform::getLocalMat4() const {
  glm::mat4 modelMatrix = glm::mat4(1.0f);
  modelMatrix = glm::translate(modelMatrix, position);
  modelMatrix *= glm::toMat4(rotation);
  modelMatrix = glm::scale(modelMatrix, scale);
  return modelMatrix;
}

void Transform::setRotation(float x, float y, float z) {
  rotation = glm::quat(glm::vec3(x, y, z));
}