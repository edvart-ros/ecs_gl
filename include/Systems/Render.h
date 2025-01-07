#pragma once
#include "Common.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Transform.h"

void Render(const Mesh &, const Material &, const Transform &);
void RenderBatch(const Mesh &, const Material &, const Transform tfList[],
                 const int N);