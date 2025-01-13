#pragma once

#include "Components/SkinnedMesh.h"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

namespace SkinnedMeshImporter {
SkinnedMesh loadSkinnedMesh(const std::string &name);
SkinnedMesh processNode(aiNode *node, const aiScene *scene);
SkinnedMesh processMesh(aiMesh *mesh, const aiScene *scene);
void processAnimation(aiAnimation *animation, const aiScene *scene);
}; // namespace SkinnedMeshImporter