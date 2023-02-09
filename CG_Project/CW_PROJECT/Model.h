#pragma once
#include <vector>
#include <string>
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
class Model
{
public:
	Model(string path);
	vector<Mesh> meshes;
	string directory;
	void Draw(Shader *shader);
	vector<Texture> textures_loaded;
	
private:
	void loadModel(string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	unsigned int TextureFromFile(const char *path, const string &directory);
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};

