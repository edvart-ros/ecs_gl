#include "Window.h"
#include "Input/Input.h"

void framebuffer_resize_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

GLFWwindow *setupWindow(int width, int height) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(width, height, "hiiii", NULL, NULL);
  if (window == NULL) {
    printf("Failed to create GLFW window! \n");
    glfwTerminate();
    return nullptr;
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(0);

  if (glewInit() != GLEW_OK) {
    printf("Failed to initialize glew! \n");
    return nullptr;
  }
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  int w, h;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
  glfwSetCursorPosCallback(window, mouse_callback);
  glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
  glEnable(GL_DEPTH_TEST);
  return window;
}
