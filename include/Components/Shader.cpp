#include "Shader.h"

Shader::Shader() : id(0){};
Shader::Shader(const std::string &shaderName) {
  this->id = createShaderProgramFromName(shaderName);
}

void Shader::use() { glUseProgram(this->id); }

void Shader::setMat4(const char *name, const glm::mat4 &mat4) {
  int matLoc = glGetUniformLocation(this->id, name);
  if (matLoc == -1) {
    printf("ERROR: failed to get uniform location of '%s' \n", name);
    return;
  }
  glUniformMatrix4fv(matLoc, 1, GL_FALSE, glm::value_ptr(mat4));
}

void Shader::setFloat(const char *name, float val) {
  int matLoc = glGetUniformLocation(this->id, name);
  if (matLoc == -1) {
    // printf("ERROR: failed to get uniform location of '%s' \n", name);
    return;
  }
  glUniform1f(matLoc, val);
}

unsigned int createShaderProgramFromName(const std::string &shaderName) {
  std::string vertShaderPath = SHADER_PATH + shaderName + "/vert.glsl";
  std::string fragShaderPath = SHADER_PATH + shaderName + "/frag.glsl";
  std::string vertCode = parseShaderFile(vertShaderPath);
  std::string fragCode = parseShaderFile(fragShaderPath);
  unsigned int vertShader = createVertexShader(vertCode);
  unsigned int fragShader = createFragmentShader(fragCode);
  if ((fragShader == 0) || (vertShader == 0)) {
    return 0;
  }
  return createShaderProgram(vertShader, fragShader);
}

unsigned int createVertexShader(const std::string &shaderSource) {
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const char *shaderSourceC = shaderSource.c_str();
  glShaderSource(vertexShader, 1, &shaderSourceC, NULL);
  glCompileShader(vertexShader);
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    printf("FAILED TO COMPILE VERTEX SHADER \n");
    printf("%s", infoLog);
    return 0;
  }
  return vertexShader;
}

unsigned int createFragmentShader(const std::string &shaderSource) {
  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char *shaderSourceC = shaderSource.c_str();
  glShaderSource(fragmentShader, 1, &shaderSourceC, NULL);
  glCompileShader(fragmentShader);
  int success;
  char infoLog[512];
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    printf("FAILED TO COMPILE FRAGMENT SHADER \n");
    printf("%s", infoLog);
    return 0;
  }
  return fragmentShader;
}

unsigned int createShaderProgram(unsigned int vertexShader,
                                 unsigned int fragmentShader) {
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  int success;
  char infoLog[512];
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    printf("FAILED TO LINK SHADER PROGRAM \n");
    printf("%s", infoLog);
    return 0;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  return shaderProgram;
}

std::string parseShaderFile(const std::string &path) {
  std::string code;
  std::ifstream file;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    file.open(path);
    std::stringstream stream;
    stream << file.rdbuf();
    file.close();
    code = stream.str();
  } catch (std::ifstream::failure &e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << path
              << std::endl;
    return "";
  }

  return code;
}
