#include "Path.h"

std::filesystem::path project_root =
    std::filesystem::path(__FILE__).parent_path().parent_path().parent_path();

std::string MODEL_PATH = project_root.string() + "/assets/models/";
std::string SHADER_PATH = project_root.string() + "/assets/shaders/";
std::string TEXTURE_PATH = project_root.string() + "/assets/textures/";