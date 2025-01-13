#pragma once
#include "Common.h"
#include "Components/Material.h"
#include "Components/Mesh.h"
#include "Components/Transform.h"
#include "Rendering/Camera/Camera.h"

void RenderMesh(const Mesh &, const Material &, const Transform &,
                const Camera &);
