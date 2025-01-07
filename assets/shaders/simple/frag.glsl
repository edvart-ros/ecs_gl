#version 330 core

uniform sampler2D diffuseMap; 
uniform sampler2D specularMap; 
uniform sampler2D normalMap; 

in vec2 uv;
in vec3 normal;
in vec4 wPos;
out vec4 FragColor;

void main() {
    FragColor = vec4(uv.x, uv.y, 0.0, 1.0);
    FragColor = vec4((wPos.x/10.0*0.5)+0.5, 0.5, (wPos.z/10.0*0.5)+0.5, 1.0);
    // FragColor = texture(normalMap, uv);
}   
