#pragma once
#include "Common.h"
#include "Components/Mesh.h"
#include "Core/MeshImporter.h"

class MeshManager {
public:
  MeshManager();
  Mesh &mesh(const std::string &name);

private:
  std::unordered_map<std::string, Mesh> meshes;
};

extern MeshManager meshMan;