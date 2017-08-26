#version 430 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 uViewTransform, uModelTransform, uProjectTransform;  

out vec4 uPixelColor;

void main() {
    //gl_Position = uModelTransform * vec4(position, 1.0);
	gl_Position = uProjectTransform * uViewTransform * uModelTransform * vec4(position, 1.0);
	uPixelColor = color;
}
