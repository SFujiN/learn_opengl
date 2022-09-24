#version 330 core

uniform float blueChange;

out vec4 FragColor;
in vec3 ourColor;

void main()
{
	FragColor = vec4(ourColor.x - blueChange, ourColor.y - blueChange, ourColor.z + blueChange, 1.0f);
}

