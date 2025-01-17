#pragma once
#include "Common.h"
#include "Core/Path.h"
#include <fstream>
#include <sstream>

struct Shader {
  unsigned int id;
  Shader();
  Shader(const std::string &shaderName);
  void use();
  void setMat4(const char *name, const glm::mat4 &mat4);
  void setFloat(const char *name, const float val);
  void setVec3(const char *name, glm::vec3 &vec);
};

unsigned int createVertexShader(const std::string &shaderSource);
unsigned int createFragmentShader(const std::string &shaderSource);
unsigned int createShaderProgram(unsigned int vertexShader,
                                 unsigned int fragmentShader);
unsigned int createShaderProgramFromName(const std::string &shaderName);
std::string parseShaderFile(const std::string &path);