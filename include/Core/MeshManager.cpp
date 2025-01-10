
#include "MeshManager.h"

MeshManager::MeshManager(){};

Mesh &MeshManager::mesh(const std::string &name){
    if (meshes.find(name) == meshes.end()){
        std::cout << "loading Mesh " << name << std::endl;
        meshes[name] = loadMesh(name);
    } else {
        std::cout << "Using cached Mesh " << name << std::endl;
    }
    return meshes[name];
}
