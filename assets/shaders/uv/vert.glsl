#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal; 
layout (location = 2) in vec2 aUv; 
out vec2 uv;
out vec3 normal;
out vec4 wPos;
 
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // normal = aNormal;
    uv = aUv; 
    mat3 normalMatrix = mat3(transpose(inverse(view * model)));
    normal = normalMatrix * aNormal;
    uv = aUv;
    wPos = model*vec4(aPos, 1.0); 
    gl_Position = projection*view*wPos;
}