#include "ShaderManager.h"
#include "Components/Shader.h"

void ShaderManager::shaderChangeCallback(
    ConstFSEventStreamRef streamRef, void *clientCallBackInfo, size_t numEvents,
    void *eventPaths, const FSEventStreamEventFlags eventFlags[],
    const FSEventStreamEventId eventIds[]) {

  ShaderManager *self = static_cast<ShaderManager *>(clientCallBackInfo);
  char **paths = static_cast<char **>(eventPaths);
  for (size_t i = 0; i < numEvents; i++) {
    self->reloadShader(paths[i]);
  }
}
ShaderManager::ShaderManager() {
  CFStringRef mypath =
      CFSTR("/Users/edvart/Programming/ecs_gl/assets/shaders/");
  CFArrayRef pathsToWatch =
      CFArrayCreate(NULL, (const void **)&mypath, 1, NULL);

  CFAbsoluteTime latency = 0.1;

  FSEventStreamContext context = {0};
  context.info = this;
  this->stream = FSEventStreamCreate(
      NULL, &this->shaderChangeCallback, &context, pathsToWatch,
      kFSEventStreamEventIdSinceNow, latency, kFSEventStreamCreateFlagNone);

  FSEventStreamScheduleWithRunLoop(this->stream, CFRunLoopGetCurrent(),
                                   kCFRunLoopDefaultMode);
  FSEventStreamStart(stream);
}

Shader &ShaderManager::shader(const std::string &name) {
  if (shaders.find(name) == shaders.end()) {
    std::cout << "loading shader " << name << std::endl;
    shaders[name] = Shader(name);
  } else {
    std::cout << "Using cached shader " << name << std::endl;
  }
  return shaders[name];
}

void ShaderManager::hotReload() {
  CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0, true);
}

void ShaderManager::reloadShader(const char *path) {
  std::filesystem::path fsPath(path);
  std::string shaderName = fsPath.parent_path().filename().string();
  std::cout << "loading shader: " << shaderName << std::endl;
  const unsigned int id = createShaderProgramFromName(shaderName);
  if (id != 0) {
    shaders[shaderName].id = createShaderProgramFromName(shaderName);
  }
}