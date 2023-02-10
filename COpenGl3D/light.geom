#version 330
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;
uniform vec3 lightpos;
uniform vec3 campos;
out vec3 gcolor;
uniform mat4 ProjectionMat;
uniform mat4 ModelMat;
uniform mat4 ViewMat;
out vec2 texcoord;
out float texnum;
out vec3 normall;
out vec3 light11;
out vec3 camlight1;

in VS_OUT
{
    vec2 TexCoords;
	float TexNum;
	vec3 VertexPos;
} gs_in[];


float dot3(vec3 a,vec3 b)
{
	float r = a.x * b.x + a.y * b.y + a.z * b.z;
	return r;
}

vec3 GetNormal()
{
   //vec3 a = vec3(gl_in[0].gl_Position - gl_in[2].gl_Position);
   //vec3 b = vec3(gl_in[1].gl_Position - gl_in[2].gl_Position);
   vec3 a1 = gs_in[0].VertexPos - gs_in[2].VertexPos;
   vec3 b1 = gs_in[1].VertexPos - gs_in[2].VertexPos;
   return -normalize(cross(a1, b1));
} 
float GetFactor(vec3 a,vec3 b)
{
	
	float angle = degrees(acos(dot(a,b)));
	
	
	return 1-abs(angle)/90;
	
	
}





void main()
{	
	bool useFonarik = false;
	vec3 lightposition = vec3(0,0,10);
	
	vec3 norm = GetNormal();
	
	
	vec3 center = (gs_in[0].VertexPos + gs_in[1].VertexPos + gs_in[2].VertexPos)/3;
	
	vec3 lighth = normalize(vec3(-1,-1,-1));	
	vec3 light1 = normalize(gs_in[0].VertexPos-lightposition);
	vec3 light2 = normalize(gs_in[1].VertexPos-lightposition);
	vec3 light3 = normalize(gs_in[2].VertexPos-lightposition);
	vec3 camlight = normalize(gs_in[0].VertexPos-campos);
	
	float camfactor = GetFactor(norm,camlight);
	float factor = GetFactor(norm,lighth);
	float factor1 = GetFactor(norm,light1);
	float factor2 = GetFactor(norm,light2);
	float factor3 = GetFactor(norm,light3);
	
	
	
	factor1 = factor1/2+factor/3+camfactor+0.2;
	factor2 = factor2/2+factor/3+camfactor+0.2;
	factor3 = factor3/2+factor/3+camfactor+0.2;
	
	//factor1 = factor1/2+factor/3+0.5;
	//factor2 = factor2/2+factor/3+0.5;
	//factor3 = factor3/2+factor/3+0.5;
	
	
	
	
	
    gl_Position = gl_in[0].gl_Position; 	
	gcolor = vec3(factor1,factor1,factor1);		
	texcoord = gs_in[0].TexCoords;	
	texnum = gs_in[0].TexNum;
	normall = norm;
	light11 = light1;
	camlight1 = camlight;
    EmitVertex();
	
	gl_Position = gl_in[1].gl_Position; 	
	gcolor = vec3(factor2,factor2,factor2);		
	texcoord = gs_in[1].TexCoords;	
	texnum = gs_in[1].TexNum;
	normall = norm;
	light11 = light2;
	camlight1 = camlight;
    EmitVertex();
	
	gl_Position = gl_in[2].gl_Position; 	
	gcolor = vec3(factor3,factor3,factor3);		
	texcoord = gs_in[2].TexCoords;
	texnum = gs_in[2].TexNum;
	normall = norm;
	light11 = light3;
	camlight1 = camlight;
    EmitVertex();		
    EndPrimitive();
   
 
}  