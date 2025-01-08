#pragma once

#include "Components/Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

Mesh loadMesh(const std::string &name);
std::vector<Mesh> loadMeshes(const std::string &path);
void processNode(aiNode *node, const aiScene *scene, std::vector<Mesh> &meshes);
Mesh processMesh(aiMesh *mesh, const aiScene *scene);