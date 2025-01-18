#version 330 core

uniform sampler2D diffuseMap; 
uniform sampler2D specularMap; 
uniform sampler2D normalMap; 
uniform sampler2D animationMap; 
uniform float time;

in vec2 uv;
in vec2 uv2;
in vec3 normal;
in float frameNorm;

out vec4 FragColor;

void main() {
    FragColor = vec4(uv2, frameNorm, 1.0);
    FragColor = texture(animationMap, vec2(uv2.x, frameNorm));
}   
