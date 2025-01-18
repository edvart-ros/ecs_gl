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
uniform vec3 minBounds;
uniform vec3 maxBounds;
uniform float time;             
uniform float frameRate;
uniform float startFrame;
uniform float endFrame;
uniform sampler2D animationMap; 

void main()
{
    uv = vec2(aUv.x, 1.0-aUv.y);
    uv2 = vec2(aUv2.x, aUv2.y);
    float nFrames = float(textureSize(animationMap, 0).y); 
    float frameSize = 1.0 / nFrames;

    // debug start/end frame
    startFrame; endFrame;
    float startFrameNorm = (startFrame+0.5)/nFrames;
    float endFrameNorm = (endFrame+0.5)/nFrames;
    frameNorm = mix(startFrameNorm, endFrameNorm, mod(time*frameRate/nFrames, 1.0));

    // debug
    vec3 offset = textureLod(animationMap, vec2(uv2.x, frameNorm), 0).xyz;
    offset = mix(minBounds, maxBounds, offset);
    vec3 nPos =  offset;
    gl_Position = projection * view * model * vec4(nPos, 1.0);
    
}