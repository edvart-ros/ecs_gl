#pragma once
#include "Common.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Transform.h"
#include "Rendering/Camera/Camera.h"

void Render(const Mesh &, const Material &, const Transform &, const Camera &);
void RenderBatch(const Mesh &, const Material &, const Transform tfList[],
                 const int N);