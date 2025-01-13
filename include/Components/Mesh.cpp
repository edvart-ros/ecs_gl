#include "Mesh.h"

Mesh::Mesh() : vertices(), indices(){};

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
  this->vertices = vertices;
  this->indices = indices;
  // int numVerts = vertices.size();
  // for (int i = 0; i < vertices.size(); i++) {
  //   this->vertices[i].uv2 = glm::vec2((i + 0.5) / numVerts, 0.0);
  //   std::cout << i << std::endl;
  //   std::cout << this->vertices[i].uv2.x << std::endl;
  // }

  glGenVertexArrays(1, &this->VAO);
  glGenBuffers(1, &this->VBO);
  glGenBuffers(1, &this->EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
               &(this->vertices[0]), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               this->indices.size() * sizeof(unsigned int), &(this->indices[0]),
               GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void *)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex),
                        (void *)(sizeof(glm::vec3)));
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(Vertex),
                        (void *)(sizeof(glm::vec3) * 2));
  glEnableVertexAttribArray(3);
  glVertexAttribPointer(3, 2, GL_FLOAT, GL_TRUE, sizeof(Vertex),
                        (void *)(sizeof(glm::vec3) * 2 + sizeof(glm::vec2)));

  glBindVertexArray(0);
};
