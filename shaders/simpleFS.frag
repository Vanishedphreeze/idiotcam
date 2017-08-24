#version 430 core

uniform vec4 uPixelColor;
out vec4 color;

void main() {
    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
	color = uPixelColor;
}
