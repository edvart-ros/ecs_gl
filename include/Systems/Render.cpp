#include "Render.h"

void RenderMesh(const Mesh &mesh, const Material &material,
                const Transform &transform, const Camera &camera) {

  material.shader.use();
  material.shader.setMat4("view", camera.viewMatrix);
  material.shader.setMat4("projection", camera.projectionMatrix);
  glBindVertexArray(mesh.VAO);
  int modelLoc = glGetUniformLocation(material.shader.id, "model");
  glm::mat4 modelMatrix = transform.getLocalMat4();
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
  if (material.textures.diffuse.id) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, material.textures.diffuse.id);
    glUniform1i(glGetUniformLocation(material.shader.id, "diffuseMap"), 0);
  }

  if (material.textures.normal.id) {
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, material.textures.normal.id);
    glUniform1i(glGetUniformLocation(material.shader.id, "normalMap"), 1);
  }

  if (material.textures.specular.id) {
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, material.textures.specular.id);
    glUniform1i(glGetUniformLocation(material.shader.id, "specularMap"), 2);
  }

  if (material.textures.animation.id) {
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, material.textures.animation.id);
    glUniform1i(glGetUniformLocation(material.shader.id, "animationMap"), 2);
  }

  glActiveTexture(GL_TEXTURE0);
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}
