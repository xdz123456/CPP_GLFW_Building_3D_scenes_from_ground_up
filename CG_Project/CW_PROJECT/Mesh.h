#pragma once
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <GL/glad.h>
#include <string>
#include <vector>
#include "Shader.h"
using namespace std;
struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture {
	unsigned int id;
	string type;
	string path;
};

class Mesh
{
public: 
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	void Draw(Shader* shader);

private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();
};

