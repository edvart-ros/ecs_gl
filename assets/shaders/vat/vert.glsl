#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aUv;
layout (location = 3) in vec2 aUv2;

out vec2 uv;
out vec2 uv2;
out float frameNorm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;             
uniform sampler2D animationMap; 

void main()
{
    uv = vec2(aUv.x, 1.0-aUv.y);
    uv2 = vec2(aUv2.x, aUv2.y);
    float nFrames = float(textureSize(animationMap, 0).y); 
    float frameSize = 1.0 / nFrames;                      
    vec3 m = vec3(-0.78, -0.08, -0.81);                      
    vec3 M = vec3(0.59, 1.45, 0.99);                         
    frameNorm = mod(time * 0.15, 1.0);
    vec3 offset = texture(animationMap, vec2(uv2.x, frameNorm)).xyz;
    offset = mix(m, M, offset);
    vec3 nPos =  offset;
    gl_Position = projection * view * model * vec4(nPos, 1.0);
}
