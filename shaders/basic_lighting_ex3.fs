#version 330 core
out vec4 FragColor;

in vec3 Result;

uniform vec3 objectColor;

void main() {
  FragColor = vec4(Result * objectColor, 1.0f);
}
