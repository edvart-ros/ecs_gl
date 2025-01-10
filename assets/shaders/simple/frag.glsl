#version 330 core

uniform sampler2D diffuseMap; 
uniform sampler2D specularMap; 
uniform sampler2D normalMap; 

in vec2 uv;
in vec3 normal;
in vec4 wPos;
out vec4 FragColor;

void main() {
    FragColor = texture(specularMap, uv);
    FragColor = texture(diffuseMap, uv);
    FragColor = vec4(1.0, 0.5, 0.3, 1.0);
}   
