#version 330 core
in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

struct Material {
    vec3 ambient;
	vec3 diffuse;
	vec3 specular;
    float shininess;
}; 

struct LightPoint {
    float constant;
    float linear;
    float quadratic;
    vec3 lightPos;
	vec3 lightDirU;
	vec3 lightColor;
}; 

struct LightSpot{
	float cosPhyInner;
	float cosPhyOutter;
	vec3 lightPos;
	vec3 lightDirU;
	vec3 lightColor;
};

uniform LightPoint LightP;
uniform LightSpot LightS1;
uniform LightSpot LightS2;

uniform sampler2D text_d;
uniform sampler2D text_s;
uniform Material material;

uniform vec3 objColor;
uniform vec3 ambientColor;
uniform vec3 cameraPos;

out vec4 FragColor;

//Set the point light
vec3 CaluP(){
	float dis  = length(LightP.lightPos - FragPos);
	float attenuation = 1.0 / (LightP.constant + LightP.linear * dis + LightP.quadratic * (dis * dis));
	
	vec3 lightDir = normalize(LightP.lightPos - FragPos);
	vec3 reflectVec = reflect(-LightP.lightDirU, Normal);

	vec3 cameraVec = normalize(cameraPos - FragPos);
	vec3 specular =  texture(text_s, TexCoord).rgb * pow(max(dot(reflectVec, cameraVec),0), material.shininess) * LightP.lightColor;

	vec3 diffuse = texture(text_d, TexCoord).rgb * max(dot(lightDir, Normal), 0) * LightP.lightColor;

	vec3 ambient = texture(text_d, TexCoord).rgb  * ambientColor;
	vec3 result = ((ambient + diffuse + specular) * objColor);
	return result;
}

//Set the spot light
vec3 CaluS(LightSpot LightS){


	vec3 lightDir = normalize(LightS.lightPos - FragPos);
	vec3 reflectVec = reflect(-LightS.lightDirU, Normal);

	vec3 cameraVec = normalize(cameraPos - FragPos);
	vec3 specular =   texture(text_s, TexCoord).rgb * pow(max(dot(reflectVec, cameraVec),0), material.shininess) * LightS.lightColor;

	vec3 diffuse = texture(text_d, TexCoord).rgb * max(dot(lightDir, Normal), 0) * LightS.lightColor;

	//ambient
	vec3 ambient = texture(text_d, TexCoord).rgb  * ambientColor;
	
	float theta = dot(lightDir, normalize(-LightS.lightDirU)); 
    float epsilon = (LightS.cosPhyInner - LightS.cosPhyOutter);
    float intensity = clamp((theta - LightS.cosPhyOutter) / epsilon, 0.0, 1.0);
    diffuse  *= intensity;
    specular *= intensity;

	float dis  = length(LightS.lightPos - FragPos);
	float attenuation = 1.0 / (LightP.constant + LightP.linear * dis + LightP.quadratic * (dis * dis));

	ambient  *= attenuation; 
    diffuse   *= attenuation;
    specular *= attenuation;  

	vec3 result = ambient + diffuse + specular;
	return result;

}

void main(){   

	
	vec3 result = CaluP();
	result += CaluS(LightS1);

	result += CaluS(LightS2);
	
	FragColor = vec4(result, 1.0f);
	
}

