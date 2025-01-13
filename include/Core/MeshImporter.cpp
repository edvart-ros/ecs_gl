#include "MeshImporter.h"
#include "assimp/scene.h"

Mesh loadMesh(const std::string &name) {
  std::vector<Mesh> meshes = loadMeshes(MODEL_PATH + name);
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  int vertsAdded = 0;

  for (int i = 0; i < meshes.size(); i++) {
    std::vector<Vertex> &subVerts = meshes[i].vertices;
    vertices.insert(vertices.end(), subVerts.begin(), subVerts.end());
    std::vector<unsigned int> &subInds = meshes[i].indices;
    for (int j = 0; j < subInds.size(); j++) {
      indices.push_back(subInds[j] + vertsAdded);
    }
    vertsAdded += subVerts.size();
  }
  return Mesh(vertices, indices);
}

std::vector<Mesh> loadMeshes(const std::string &path) {
  Assimp::Importer importer;
  std::vector<Mesh> meshes;
  const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate);

  if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
      !scene->mRootNode) {
    printf("ASSIMP ERROR: %s \n", importer.GetErrorString());
  }
  processNode(scene->mRootNode, scene, meshes);
  return meshes;
}

void processNode(aiNode *node, const aiScene *scene,
                 std::vector<Mesh> &meshes) {
  if (node->mNumMeshes > 0) {
    for (int i = 0; i < node->mNumMeshes; i++) {
      aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
      Mesh nodeMesh = processMesh(mesh, scene);
      meshes.push_back(nodeMesh);
    }
  }
  for (int i = 0; i < node->mNumChildren; i++) {
    processNode(node->mChildren[i], scene, meshes);
  }
}

Mesh processMesh(aiMesh *mesh, const aiScene *scene) {
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
    if (mesh->mTextureCoords[1]) {
      vertex.uv2.x = mesh->mTextureCoords[1][i].x;
      vertex.uv2.y = mesh->mTextureCoords[1][i].y;
    }
    vertices.push_back(vertex);
  }

  for (int i = 0; i < mesh->mNumFaces; i++) {
    aiFace face = mesh->mFaces[i];
    for (int j = 0; j < face.mNumIndices; j++) {
      indices.push_back(face.mIndices[j]);
    }
  }

  Mesh resultMesh(vertices, indices);
  return resultMesh;
};
