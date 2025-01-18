#include "Animation.h"
#include "Logging/Logging.h"

using json = nlohmann::json;

Animation::Animation(float frameRate)
    : frameRate(frameRate), minBounds(), maxBounds(){};

Animation::Animation(float frameRate, const std::string &name) {
  this->frameRate = frameRate;
  std::ifstream f(ANIMATION_PATH + name);
  json j = json::parse(f);
  minBounds = glm::vec3(j["min"]["x"], j["min"]["y"], j["min"]["z"]);
  maxBounds = glm::vec3(j["max"]["x"], j["max"]["y"], j["max"]["z"]);
  animationIdx = 0;
  printVec3(minBounds);
  printVec3(maxBounds);
  return;
}