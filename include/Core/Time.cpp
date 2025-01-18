#include "Time.h"

Time::Time() : current(0.0f), previous(0.0f), delta(0.000001f){};
void Time::update() {
  current = glfwGetTime();
  delta = current - previous;
  previous = current;
}