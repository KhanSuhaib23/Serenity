#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in float textureIndex;
layout (location = 2) in vec2 textureCoordinate;
layout (location = 3) in vec4 color;

uniform mat4 projection_matrix = mat4(1.0);
uniform mat4 model_matrix = mat4(1.0);
uniform mat4 view_matrix = mat4(1.0);

out DATA
{
	vec4 color;
	vec2 textureCoordinate;
	float textureIndex;

}vs_out;

void main()
{
	gl_Position = projection_matrix * view_matrix * model_matrix * vec4(position.xyz, 1.0f);
	vs_out.color = color;
	vs_out.textureCoordinate = textureCoordinate;
	vs_out.textureIndex = textureIndex;
}