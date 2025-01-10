#pragma once
#include "Common.h"
#include "Components/Shader.h"
#include "Path.h"
#include <CoreServices/CoreServices.h>
#include <filesystem>

class ShaderManager {
public:
  ShaderManager();
  Shader &shader(const std::string &name);
  void hotReload();

private:
  std::unordered_map<std::string, Shader> shaders;
  FSEventStreamRef stream;
  void reloadShader(const char *path);
  static void shaderChangeCallback(ConstFSEventStreamRef streamRef,
                                   void *clientCallBackInfo, size_t numEvents,
                                   void *eventPaths,
                                   const FSEventStreamEventFlags eventFlags[],
                                   const FSEventStreamEventId eventIds[]);
};

extern ShaderManager shaderMan;