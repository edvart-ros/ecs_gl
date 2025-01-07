#include "Mesh.h"

Mesh::Mesh() : vertices(), indices() {};

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
  this->vertices = vertices;
  this->indices = indices;
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

  glBindVertexArray(0);
};
