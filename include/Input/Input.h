#pragma once
#include "Common.h"

struct Keys {
  bool Q = false;
  bool W = false;
  bool E = false;
  bool A = false;
  bool S = false;
  bool D = false;
};

struct Mouse {
  float deltaX = 0;
  ;
  float deltaY = 0;
  float x = 0;
  float y = 0;
};

extern Keys keys;
extern Mouse mouse;

void processInputs(GLFWwindow *window, Keys &keys);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
