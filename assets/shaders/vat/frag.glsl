#version 330 core

uniform sampler2D diffuseMap; 
uniform sampler2D specularMap; 
uniform sampler2D normalMap; 
uniform sampler2D animationMap; 
uniform float time;

in vec2 uv;
in vec2 uv2;
in vec3 normal;

out vec4 FragColor;

void main() {
    // FragColor = texture(animationMap, uv);
    
    FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    FragColor = vec4(uv.x, uv.y, 0.0, 1.0);
}   
