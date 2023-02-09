#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glad.h>
#include <GL/glfw3.h>
#include <GL/glad.h>
#include <GL/glfw3.h>
using namespace std;

//Constructor for Shader
Shader::Shader(const char* vertexPath, const char* fragmentPath) {
	//Init the vertex shader and fragment shader
	ifstream vertexfile;
	ifstream fragmentFile;
	stringstream vertexSStream;
	stringstream fragmentSStream;
	//Open shader and fragment shader's file
	vertexfile.open(vertexPath);
	fragmentFile.open(fragmentPath);
	vertexfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	//Load Shader
	try 
	{
		if (!vertexfile.is_open() || !fragmentFile.is_open()) {
			throw exception("open file error");
		}
		vertexSStream << vertexfile.rdbuf();
		fragmentSStream << fragmentFile.rdbuf();

		vertexString = vertexSStream.str();
		fragmentString = fragmentSStream.str();
		
		vertexSource = vertexString.c_str();
		fragmentSource = fragmentString.c_str();
		
		//Init Vertex Shader
		unsigned int vertex, fragment;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);
		checkCompileError(vertex, "VERTEX");

		//Init Fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);
		checkCompileError(fragment, "FRAGMENT");

		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		checkCompileError(ID, "PROGRAM");
 	}

	//Print the error information
	catch (const std::exception& ex) 
	{
		printf(ex.what());
	}
	

}

//Use the shader
void Shader::use() {
	glUseProgram(ID);
}

//Check the Error
void Shader::checkCompileError(unsigned int ID, string type) {
	int success;
	char infoLog[512];

	if (type != "PROGRAM") {
		glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(ID, 512, NULL, infoLog);
			cout << "Shder error: " << infoLog << endl;
		}
	}

	else {
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			cout << "Compile error: " << infoLog << endl;
		}
	}
}

//Set the Uniform vec3
void Shader::SetUniform3f(const char* paramNameString, glm::vec3 param){

	glUniform3f(glGetUniformLocation(ID, paramNameString), param.x, param.y, param.z);

}

//Set the float
void Shader::SetUniform1f(const char* paramNameString, float param) {
	glUniform1f(glGetUniformLocation(ID, paramNameString), param);
}

//Set the image
void Shader::SetUniform1i(const char* paramNameString, int slot) {

	glUniform1i(glGetUniformLocation(ID, paramNameString), slot);
}