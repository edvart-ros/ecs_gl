#include "Camera.h"

const float MOVE_SPEED = 5.0f;
const float ANGULAR_SPEED = 0.03f;

Camera::Camera() {
  this->projectionMatrix =
      glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
  this->transform = Transform();
  this->transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
  this->initViewMatrix();
  this->target = glm::vec3(0.0f, 0.0f, 0.0f);
  this->theta = 0.001f;
  this->phi = 0.001f;
  this->R = 10.0f;
}

void Camera::update(Keys &keys, Mouse &mouse) {
  this->transform.position.y = this->target.y + R * cosf(this->theta);
  this->transform.position.x =
      this->target.x + R * sinf(this->theta) * cosf(this->phi);
  this->transform.position.z =
      this->target.z + R * sinf(this->theta) * sinf(this->phi);

  this->forward = glm::normalize(target - this->transform.position);
  this->right = glm::normalize(glm::cross(this->forward, WORLD_UP));
  this->up = glm::cross(this->right, this->forward);

  this->viewMatrix = glm::lookAt(this->transform.position, target, up);

  this->phi -= ANGULAR_SPEED * gTime.delta * mouse.deltaX;
  this->theta += ANGULAR_SPEED * gTime.delta * mouse.deltaY;

  this->theta = glm::clamp(this->theta, 0.001f, glm::pi<float>() - 0.001f);
  this->phi = glm::mod(this->phi, glm::two_pi<float>());

  if (keys.UP)
    this->R -= gTime.delta * MOVE_SPEED;
  if (keys.DOWN)
    this->R += gTime.delta * MOVE_SPEED;
}

void Camera::initViewMatrix() {
  this->viewMatrix = glm::mat4(1.0f);
  this->viewMatrix =
      glm::translate(this->viewMatrix, -this->transform.position);
}
