#include "Material.h"

//Constructor for Material
Material::Material(Shader* _shader, glm::vec3 _diffuse, glm::vec3 _specular, glm::vec3 _ambient, float _shininess)
{
	shader = _shader;
	diffuse = _diffuse;
	specular = _specular;
	shininess = _shininess;
}