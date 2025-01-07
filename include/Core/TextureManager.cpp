#include "TextureManager.h"

TextureManager::TextureManager() : textures() {}

Texture &TextureManager::tex(const std::string &name) {
  if (textures.find(name) == textures.end()) {
    std::cout << "loading texture " << name << std::endl;
    textures[name] = CreateTex2D(TEXTURE_PATH + name);
  } else {
    std::cout << "Using cached texture " << name << std::endl;
  }
  return textures[name];
}

Texture TextureManager::CreateTex2D(const std::string &path) {
  int width, height, nrChannels;
  const char *cPath = path.c_str();
  unsigned char *data = stbi_load(cPath, &width, &height, &nrChannels, 0);
  Texture texture;
  unsigned int id;
  if (!data) {
    printf("ERROR: FAILED TO LOAD TEXTURE: %s \n", cPath);
    return texture;
  }
  glGenTextures(1, &id);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  int glTexFormat;
  int glDataFormat;
  switch (nrChannels) {
  case 1:
    glTexFormat = GL_COMPRESSED_RED;
    glDataFormat = GL_RED;
    break;
  case 2:
    glTexFormat = GL_COMPRESSED_RG;
    glDataFormat = GL_RG;
    break;
  case 3:
    glTexFormat = GL_COMPRESSED_RGB;
    glDataFormat = GL_RGB;
    break;
  case 4:
    glTexFormat = GL_COMPRESSED_RGBA;
    glDataFormat = GL_RGBA;
    break;
  default:
    std::cerr << "ERROR: number of texture channels must be 1-4" << std::endl;
    std::cerr << "number of channels: " << nrChannels << std::endl;
    stbi_image_free(data);
    return texture;
  }

  glTexImage2D(GL_TEXTURE_2D, 0, glTexFormat, width, height, 0, glDataFormat,
               GL_UNSIGNED_BYTE, data);

  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(data);
  texture.id = id;
  texture.path = path;
  return texture;
}