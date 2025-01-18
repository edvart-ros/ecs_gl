#version 330 core

uniform sampler2D diffuseMap; 
uniform sampler2D specularMap; 
uniform sampler2D normalMap; 

in vec2 uv;
in vec3 normal;
in vec4 wPos;
out vec4 FragColor;

void main() {
    vec2 coord = vec2(wPos.x, wPos.z);
    vec2 grid = abs(fract(coord-0.5) - 0.5) / fwidth(coord);
    
    float lineWidth = min(grid.x, grid.y);
    float col = 1.0 - smoothstep(0.0, 1.5, lineWidth);

    if (col < 0.0001){
        discard;
    }
    if (length(coord) < 1.0){
        FragColor = vec4(coord.x, 0.0, coord.y, 1.0);
        return;
    }
    float d = length(wPos);
    float alpha = 0.3*(1.0-smoothstep(0.0, 70.0, d));
    FragColor = vec4(1.0, 1.0, 1.0, alpha);
}