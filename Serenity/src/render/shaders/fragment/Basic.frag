#version 330 core

out vec4 color;

in DATA
{
	vec4 color;
	vec2 textureCoordinate;
	float textureIndex;

}fs_in;

uniform sampler2D textures[32];

void main()
{
	int tid = int (fs_in.textureIndex);
	color = texture(textures[tid], fs_in.textureCoordinate);
}