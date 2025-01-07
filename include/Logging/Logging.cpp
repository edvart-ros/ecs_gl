#include "Logging.h"

void printMat4(const glm::mat4 &mat) {
  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 4; ++col) {
      std::cout << mat[col][row] << " ";
    }
    std::cout << std::endl;
  }
}

void printTransform(const Transform &transform) {
  std::cout << "POSITION: \n";
  std::cout << "x: " << transform.position.x << "\n";
  std::cout << "y: " << transform.position.y << "\n";
  std::cout << "z: " << transform.position.z << "\n";
}

void printVec3(const glm::vec3 &vec) {
  printf("(x: %f, y: %f, z: %f) \n", vec.x, vec.y, vec.z);
}

void printVerts(const Mesh &mesh) {
  int numVerts = mesh.indices.size();
  printf("numVerts: %d", numVerts);
}
