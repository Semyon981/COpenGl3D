#version 330
layout(location = 0) in vec3 VertexPos;
layout(location = 1) in vec2 TexturePos;
layout(location = 2) in float Texnum;
uniform mat4 ProjectionMat;
uniform mat4 ModelMat;
uniform mat4 ViewMat;
 
out VS_OUT
{
    vec2 TexCoords;
	float TexNum;
	vec3 VertexPos;
} vs_out;



void main()
{
	

	gl_Position = ProjectionMat * ViewMat * ModelMat * vec4(VertexPos,1);
	vs_out.TexCoords = TexturePos;	
	vs_out.TexNum = Texnum;
	vs_out.VertexPos = VertexPos;
	//gl_Position = ProjectionMat * ViewMat * ModelMat * vec4(TexturePos,1,1);
	
}