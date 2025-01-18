#pragma once
#include "Common.h"
#include "Core/Path.h"
#include <fstream>
#include <json/json.hpp>

struct SubAnimation {
  int startFrame;
  int endFrame;
};

struct Animation {
  float frameRate;
  glm::vec3 minBounds;
  glm::vec3 maxBounds;
  SubAnimation subAnimations[3];
  int animationIdx;
  Animation(float frameRate);
  Animation(float frameRate, const std::string &name);
};