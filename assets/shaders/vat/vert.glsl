#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aUv;
layout (location = 3) in vec2 aUv2;

out vec2 uv;
out vec2 uv2;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;             
uniform sampler2D animationMap; 

void main()
{
    float nFrames = float(textureSize(animationMap, 0).y); 
    float frameSize = 1.0 / nFrames;                      
    vec3 m = vec3(-2.84, -3.26, -2.14);                      
    vec3 M = vec3(3.75, 3.013, 2.29);                         
    float frameNorm = mod(time * 0.2, 1.0);

    vec3 offset = texture(animationMap, vec2(aUv2.x, frameNorm)).xyz;

//   "min": {
//     "x": -2.8395402431488037,
//     "y": -3.258139133453369,
//     "z": -2.130481481552124
//   },
//   "max": {
//     "x": 3.747551202774048,
//     "y": 3.012871265411377,
//     "z": 2.292975425720215
//   }

    offset = mix(m, M, offset);
    vec3 nPos =  offset;
    uv = aUv;
    uv2 = aUv2;
    gl_Position = projection * view * model * vec4(nPos, 1.0);
}
