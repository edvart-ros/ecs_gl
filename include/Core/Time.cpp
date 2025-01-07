#include "Time.h"

void updateTime(float &deltaTime, float &previousTime) {
  float t = glfwGetTime();
  deltaTime = t - previousTime;
  previousTime = t;
}