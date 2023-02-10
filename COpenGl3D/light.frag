#version 330

out vec4 fragColor;
uniform vec3 color;
uniform sampler2D texture[10];
uniform sampler2D normalmap;

uniform float shoot;
in vec3 gcolor;
in vec2 texcoord;
in float texnum;
in vec3 normall;
in vec3 light11;
in vec3 camlight1;


float GetFactor(vec3 a,vec3 b)
{
	
	float angle = degrees(acos(dot(a,b)));
	
	
	return 1-abs(angle)/90;
	
	
}


void main()
{
	
	//vec3 lighthuita = normalize(vec3(-1,-1,-1));
	//vec4 xfac = texture2D(normalmap, texcoord);
	//vec3 facnorm = normalize(cross(vec3(xfac.x,xfac.y,xfac.z), normall));
	
	//float factor = GetFactor(facnorm,light11);
	//float factorl = GetFactor(facnorm,lighthuita);
	//float camfactor = GetFactor(facnorm,camlight1);
	
	//factor = factor/2+factorl/3+0.6;
	//factor = camfactor;
	
	if (texnum == 0)
	{
		fragColor = texture2D(texture[0], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}	
	else if(texnum >0.5 && texnum < 1.5)
	{
		fragColor = texture2D(texture[1], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >1.5 && texnum < 2.5)
	{
		fragColor = texture2D(texture[2], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >2.5 && texnum < 3.5)
	{
		fragColor = texture2D(texture[3], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >3.5 && texnum < 4.5)
	{
		fragColor = texture2D(texture[4], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >4.5 && texnum < 5.5)
	{
		fragColor = texture2D(texture[5], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >5.5 && texnum < 6.5)
	{
		fragColor = texture2D(texture[6], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >6.5 && texnum < 7.5)
	{
		fragColor = texture2D(texture[7], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >7.5 && texnum < 8.5)
	{
		fragColor = texture2D(texture[8], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	else if(texnum >8.5 && texnum < 9.5)
	{
		fragColor = texture2D(texture[9], texcoord)*vec4(gcolor,1)*vec4(color,1);
	}
	
	
	
	
	
	
	
	
	
	
	
	
}