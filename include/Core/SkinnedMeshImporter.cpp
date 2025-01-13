#include "SkinnedMeshImporter.h"
#include "Components/SkinnedMesh.h"
#include "assimp/scene.h"
#include <cstdlib>

// assumes file only contains a single mesh

namespace SkinnedMeshImporter {
SkinnedMesh loadSkinnedMesh(const std::string &name) {
  Assimp::Importer importer;
  const aiScene *scene =
      importer.ReadFile(MODEL_PATH + name, aiProcess_Triangulate);
  if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
      !scene->mRootNode) {
    printf("ASSIMP ERROR: %s \n", importer.GetErrorString());
  }

  std::cout << "loading skinned mesh " << name << std::endl;
  aiAnimation *animation = scene->mAnimations[0];
  processAnimation(animation, scene);
  return processNode(scene->mRootNode, scene);
}

void processAnimation(aiAnimation *animation, const aiScene *scene) {
  std::cout << "processing animation: " << animation->mName.C_Str()
            << std::endl;
  std::cout << "number of channels: " << animation->mNumChannels << std::endl;
  std::cout << "duration: " << animation->mDuration << std::endl;
  for (int i = 0; i < animation->mNumChannels; i++) {
    aiNodeAnim *nodeAnimation = animation->mChannels[i];
  }
};

SkinnedMesh processNode(aiNode *node, const aiScene *scene) {
  aiMesh *mesh = scene->mMeshes[node->mMeshes[0]];
  SkinnedMesh nodeMesh = processMesh(mesh, scene);
  return nodeMesh;
}

SkinnedMesh processMesh(aiMesh *mesh, const aiScene *scene) {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  TextureMaps textures;

  for (int i = 0; i < mesh->mNumVertices; i++) {
    Vertex vertex;
    vertex.position.x = mesh->mVertices[i].x;
    vertex.position.y = mesh->mVertices[i].y;
    vertex.position.z = mesh->mVertices[i].z;

    if (mesh->mNormals) {
      vertex.normal.x = mesh->mNormals[i].x;
      vertex.normal.y = mesh->mNormals[i].y;
      vertex.normal.z = mesh->mNormals[i].z;
    }

    if (mesh->mTextureCoords[0]) {
      vertex.uv.x = mesh->mTextureCoords[0][i].x;
      vertex.uv.y = mesh->mTextureCoords[0][i].y;
    }
    vertices.push_back(vertex);
  }

  for (int i = 0; i < mesh->mNumFaces; i++) {
    aiFace face = mesh->mFaces[i];
    for (int j = 0; j < face.mNumIndices; j++) {
      indices.push_back(face.mIndices[j]);
    }
  }

  SkinnedMesh resultMesh(vertices, indices);
  return resultMesh;
};

}; // namespace SkinnedMeshImporter