#pragma once
#include "Common.h"

struct Time {
  float current;
  float delta;
  float previous;
  Time();
  void update();
};

extern Time gTime;
