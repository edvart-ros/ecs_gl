#include "Input.h"

void Mouse::resetDelta() {
  this->deltaX = 0.0;
  this->deltaY = 0.0;
}

void processInputs(GLFWwindow *window, Keys &keys) {
  keys.Q = (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS);
  keys.W = (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS);
  keys.E = (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS);
  keys.A = (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS);
  keys.S = (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS);
  keys.D = (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS);
  keys.UP = (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS);
  keys.DOWN = (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
  mouse.deltaX = mouse.x - xpos;
  mouse.deltaY = mouse.y - ypos;
  mouse.x = xpos;
  mouse.y = ypos;
}
