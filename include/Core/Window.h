#pragma once
#include "Input/Input.h"
#include <stdio.h>

void framebuffer_resize_callback(GLFWwindow *window, int width, int height);

GLFWwindow *setupWindow(int width, int height);
