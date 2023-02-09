#pragma once
#include "Shader.h"
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

class Material
{
public:
	Shader * shader;
	glm::vec3 diffuse;
	glm::vec3 ambient;
	glm::vec3 specular;
	float shininess;
	Material(Shader * _shader, glm::vec3 _diffuse, glm::vec3 _specular, glm::vec3 _ambient, float _shininess);
};

