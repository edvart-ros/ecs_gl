#pragma once
#include "../Common.h"
#include "Components/Mesh.h"
#include "Components/Transform.h"

void printMat4(const glm::mat4 &mat);
void printTransform(const Transform &transform);
void printVec3(const glm::vec3 &vec);
void printVerts(Mesh &mesh);