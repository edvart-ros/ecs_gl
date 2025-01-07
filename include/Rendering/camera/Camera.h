#pragma once
#include "Common.h"
#include "Components/Transform.h"
#include "Core/Time.h"
#include "Input/Input.h"
#include "Math/Geometry.h"
#include "math.h"

class Camera {
public:
  Transform transform;
  glm::mat4 viewMatrix;
  glm::mat4 projectionMatrix;
  glm::vec3 target;
  glm::vec3 forward;
  glm::vec3 up;
  glm::vec3 right;
  float R;
  float phi;
  float theta;
  Camera();
  void initViewMatrix();
  void updateProjectionMatrix();
  // void updateDirectionVector();
  void update(Keys &keys, Mouse &mouse);
};
