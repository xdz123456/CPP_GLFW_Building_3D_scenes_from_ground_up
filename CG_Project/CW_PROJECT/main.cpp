#pragma region Include_declear
#include <GL/glad.h>
#include <GL/glfw3.h>
#include <iostream>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Camera.h"
#include "Mesh.h"
#include "LightDir.h"
#include "LightPoint.h"
#include "LightSpot.h"
#include "Material.h"
#include "Model.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#pragma endregion
#pragma region Model_Data
//Position matrix
glm::vec3 objPosition[] = {
  glm::vec3(-3.0f, 3.02f, -4.4f),   //light
  glm::vec3(0.0f,  0.0f, -3.0f),	//desk
  glm::vec3(0.0f,  3.02f, -4.4f),	//monitor
  glm::vec3(0.0f,  3.02f, -2.6f),	//KeyBoard
  glm::vec3(2.0f,  3.02f, -2.6f),	//Mouse
  glm::vec3(0.0f,  0.0f, 3.0f),		//Room
  glm::vec3(0.0f,  0.0f, 0.0f),		//chair
  glm::vec3(-6.9f, 5.0f, -3.0f),	//paiting
  glm::vec3(0.0f,  9.4f, -3.0f),	//lop
  glm::vec3(0.0f,  9.4f, -3.0f),	//fly
  glm::vec3(3.0f,  3.02f, -4.4f),	//plant
  glm::vec3(6.9f,  7.0f, -3.0f),	//clock
  glm::vec3(6.88f,  7.0f, -3.0f),	//pointer
  glm::vec3(0.0f,  1.8f, -6.1f),	//window
  glm::vec3(6.0f,  0.5f, -4.4f),	//light2
  glm::vec3(-2.0f,  3.4f, 13.5f),	//door
  glm::vec3(-3.0f,  0.4f, -2.5f),	//rub
  glm::vec3(-4.3f,  2.2f, 6.0f),	//booket
  glm::vec3(5.3f,  0.4f, 6.6f),		//sofa
  glm::vec3(-5.6f,  2.6f, 7.0f),	//book
  glm::vec3(-5.8f,  4.2f, 5.6f),	//BOOK2
  glm::vec3(-5.8f,  5.7f, 7.0f),	//BOOK3
  glm::vec3(-3.0f,  3.02f,  -3.0f), //sound1
  glm::vec3(3.0f,  3.02f,  -3.0f),	//sound2
  glm::vec3(6.5f,  0.4f,  11.5f),	//plant2
  glm::vec3(5.6f,  0.4f,  1.5f),		//smalltb
  glm::vec3(0.0f,  3.36f, -3.95f),	//screen
  glm::vec3(0.0f,  3.02f, -3.1f), //desttop
  glm::vec3(0.4f,  0.4f, 6.6f),		//carpet
  glm::vec3(-5.6f,  1.2f, 4.0f),		//box1
  glm::vec3(-5.6f,  1.2f, 6.1f),	//box2
  glm::vec3(-5.8f,  1.2f, 7.9f),	//box3
  glm::vec3(1.0f,  0.6f, 6.6f),		//teapoy
  glm::vec3(-5.8f,  7.0f, 6.0f),	//cup
  glm::vec3(-5.6f,  0.4f, -5.6f)
};
//Size matrix
glm::vec3 objSize[] = {
  glm::vec3(0.9f,  0.9f,  0.9f),	//light
  glm::vec3(4.0f,  4.0f, 4.0f),		//desk
  glm::vec3(4.0f, 4.0f, 4.0f),		//monitor
  glm::vec3(5.0f, 5.0f, 5.0f),		//KeyBoard
  glm::vec3(5.0f, 5.0f, 5.0f),		//Mouse
  glm::vec3(1.5f,  1.0f, 2.0f),		//Room
  glm::vec3(5.0f, 5.0f, 5.0f),		//chair
  glm::vec3(2.0f,  2.0f, 2.0f),		//paiting
  glm::vec3(2.0f,  2.0f, 2.0f),		//lop
  glm::vec3(0.25f,  0.25f, 0.25f),	//fly
  glm::vec3(4.0f, 4.0f, 4.0f),		//plant
  glm::vec3(0.9f,  0.9f,  0.9f),	//clock
  glm::vec3(0.9f,  0.9f,  0.9f),	//pointer
  glm::vec3(4.0f,  3.4f,  3.0f),	//window
  glm::vec3(0.7f,  0.8f,  0.7f),	//light2
  glm::vec3(6.0f,  2.0f,  3.3f),	//door
  glm::vec3(0.5f,  0.5f, 0.5f),		//rub
  glm::vec3(0.8f,  0.8f, 0.8f),		//booket
  glm::vec3(2.8f,  2.8f, 2.8f),		//sofa
  glm::vec3(0.5f,  0.5f, 0.5f),		//book
  glm::vec3(0.5f,  0.5f, 0.5f),		//book2
  glm::vec3(0.5f,  0.5f, 0.5f),		//book3
  glm::vec3(0.4f,  0.4f, 0.4f),		//sound
  glm::vec3(0.4f,  0.4f, 0.4f),		//sound
  glm::vec3(2.4f,  2.0f, 2.4f),		//plant2
  glm::vec3(1.2f,  1.2f, 1.2f),		//smalltb
  glm::vec3(3.98f, 3.98f, 4.0f),		//screen
  glm::vec3(1.3f,  0.9f,  1.45f),	//desktop
  glm::vec3(1.6f,  1.2f, 1.2f),		//carpet	
  glm::vec3(0.3f,  0.3f,  0.3f),	//box1
  glm::vec3(0.3f,  0.3f,  0.3f),	//box2
  glm::vec3(0.3f,  0.3f,  0.3f),		//box3
glm::vec3(1.5f,  1.5f,  1.5f),		//teapoy
  glm::vec3(0.6f,  0.6f,  0.6f),		//cup
  glm::vec3(3.0f,  3.0f, 3.0f)
};
//Roate angel
float roateAngle[] = {
	45.0f,0.0f,0.0f,0.0f,-90.0f,
	0.0f,-90.0f,-90.0f, 0.0f, 0.0f,
	0.0f,0.0f,0.0f, 0.0f, 0.0f,
	-90.0f, 0.0f, 90.0f, -90.0f,
	-90.0f, -90.0f, -90.0f, -45.0f, -135.0f,
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	-8.0f, 0.0f, 15.0f, 0.0f, 0.0f,
	0.0f
};
//Roate matrix
glm::vec3 objRoate[] = {
  glm::vec3(0.0f,  1.0f,  0.0f),	//light
  glm::vec3(1.0f,  1.0f, 1.0f),		//desk
  glm::vec3(1.0f,  1.0f, 1.0f),		//monitor
  glm::vec3(1.0f,  1.0f, 1.0f),		//KeyBoard
  glm::vec3(0.0f,  1.0f,  0.0f),	//Mouse
  glm::vec3(0.0f,  1.0f,  0.0f),	//Room
  glm::vec3(0.0f,  1.0f,  0.0f),	//chair
  glm::vec3(0.0f,  0.0f,  1.0f),	//paiting
  glm::vec3(0.0f,  1.0f, 0.0f),		//lop
  glm::vec3(0.0f,  1.0f, 0.0f),		//fly
  glm::vec3(0.0f,  1.0f, 0.0f),		//plant
  glm::vec3(0.0f,  1.0f, 0.0f),		//clock
  glm::vec3(0.0f,  1.0f, 0.0f),		//pointer
  glm::vec3(0.0f,  1.0f, 0.0f),		//window
  glm::vec3(0.0f,  1.0f, 0.0f),		//light2
  glm::vec3(1.0f,  0.0f, 0.0f),		//door
  glm::vec3(1.0f,  0.0f, 0.0f),		//rub
  glm::vec3(0.0f,  1.0f, 0.0f),		//booket
  glm::vec3(0.0f,  1.0f, 0.0f),		//sofa
  glm::vec3(0.0f,  1.0f, 0.0f),		//BOOK1
  glm::vec3(0.0f,  1.0f, 0.0f),		//BOOK2
  glm::vec3(0.0f,  1.0f, 0.0f),		//BOOK3
  glm::vec3(0.0f,  1.0f, 0.0f),		//sound
  glm::vec3(0.0f,  1.0f, 0.0f),		//sound
  glm::vec3(0.0f,  1.0f, 0.0f),		//plant2
  glm::vec3(0.0f,  1.0f, 0.0f),		//smalltb
  glm::vec3(0.0f,  1.0f, 0.0f),			//monitor
  glm::vec3(0.0f,  1.0f, 0.0f),//desktop
  glm::vec3(0.0f,  1.0f, 0.0f),	//carpet
  glm::vec3(0.0f,  1.0f, 0.0f),		//box1
  glm::vec3(0.0f,  1.0f, 0.0f),		//box2
  glm::vec3(0.0f,  1.0f, 0.0f),		//box3
  glm::vec3(0.0f,  1.0f, 0.0f),		//teapoy
  glm::vec3(0.0f,  1.0f, 0.0f),		//cup
  glm::vec3(0.0f,  1.0f, 0.0f)
};
#pragma endregion
#pragma region Function_declear
void mouse_callback(GLFWwindow* window, double xPos, double yPos);	//Deal with the mouse callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height);	//Deal with the windows callback
void processInput(GLFWwindow *window);	//Deal with the Keyboard callback
unsigned int LoadImageToGPU(const char* filename, GLint internalFormat, GLenum format, int texttureSlot);	//Load texture to gpu
glm::mat4 Dealmodel(int i);	//Deal with the model such as transform rotate
void SetLight(Shader *myShader);	//Load to GPU
#pragma endregion
#pragma region Input_declear
//Declear the mouse position
double lastX;
double lastY;
bool firstMouse = true;
//Declear the door movement and state
int doormove = 0;
float doordis = 0.0f;
//Declear three lights' state
int light1_o = 0;
int light2_o = 0;
int light3_o = 0;
//Declear screen's state
int screen_o = 0;
//Declear cup's angel and state
int cup_o = 0;
float cup_a = 0.0f;
//Store the model's path vector
vector<string> Paths;
//Store the model vector
vector<Model> Models;
#pragma endregion
#pragma region Camera_declear
Camera camera(glm::vec3(0, 7.0f, 8.0f), glm::radians(-15.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0)); //Declear the Camera
#pragma endregion
#pragma region Light Declear
LightPoint light1 = LightPoint(glm::vec3(11.0f, 15.0f, 15.0f), glm::vec3(glm::radians(60.0f), glm::radians(60.0f), 0), glm::vec3(0.87f, 0.49f, 0.17f));
LightPoint dark = LightPoint(glm::vec3(11.0f, 15.0f, 15.0f), glm::vec3(glm::radians(60.0f), glm::radians(60.0f), 0), glm::vec3(0.2f, 0.2f, 0.2f));
LightSpot light2 = LightSpot(glm::vec3(6.0f, 5.5f, -4.4f), glm::vec3(-90.0f, 0, 0), glm::vec3(0.8f, 0.8f, 0.2f));
LightSpot light3 = LightSpot(glm::vec3(-2.2, 4.7f, -4.4f), glm::vec3(-90.0f, 0, 0), glm::vec3(0.8f, 0.0f, 0.2f));
LightSpot black = LightSpot(glm::vec3(-2.2, 4.7f, -4.4f), glm::vec3(-90.0f, 0, 0), glm::vec3(0.0f, 0.0f, 0.0f));
#pragma endregion

int main(int argc, char* argv[]) {

	string exePath = argv[0];	//Get the program's path

#pragma region OpenWindows
	//init the glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//init Window
	GLFWwindow* window = glfwCreateWindow(800, 600, "CW_PJ", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//use the windows
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	//init glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glEnable(GL_DEPTH_TEST);
#pragma endregion

#pragma region InitShaderProgram
	Shader* myShader = new Shader("vertexSource.vert", "fragmentSource.frag"); //init the shader
#pragma endregion

#pragma region Material
	//init the material
	Material * myMaterial = new Material(myShader,
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		32.0f);
#pragma endregion

#pragma region Init Model
	//Load different models
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\light.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\desk.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\monitor.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\KeyBoard.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\Mouse.obj"); 
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\untitled.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\chair.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\paiting.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\lop.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\fly.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\plant.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\clock.obj"); 
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\zhen.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\lian.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\light2.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\door.obj");  
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\rubbish.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\booket.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\sofa.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\book.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\book.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\book.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\sound.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\sound.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\plant2.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\smalltb.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\screen.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\desktop.obj"); 
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\carpet.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\box.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\box.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\box.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\teapoy.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\trophy.obj");
	Paths.push_back(exePath.substr(0, exePath.find_last_of('\\')) + "\\model\\plant2.obj");

	//Store the models to vector
	for (int i = 0; i < Paths.size(); i++)
	{
		Model model(Paths[i]);
		Models.push_back(model);
	}
#pragma endregion

#pragma region MVP Matrix
	// init model, view, proj matrix
	glm::mat4 modelMat = glm::mat4(1.0f);
	glm::mat4 viewMat = glm::mat4(1.0f);
	glm::mat4 projMat = glm::mat4(1.0f);
	projMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

#pragma endregion

	//Rander the scene
	while (!glfwWindowShouldClose(window))
	{
		//Double buffer
		glfwSwapBuffers(window);

		//Clean color buffer
		glClearColor(0, 0, 0, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//init the camera position
		viewMat = camera.GetViewMatrix();

		//Rander different model
		for (int i = 0; i < Models.size(); i++)
		{
			//Deal with the model
			modelMat = Dealmodel(i);
			
			//Set Shader Program
			myShader->use();

			//Send the MVP matrix to the GPU
			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
			glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

			//Set up the camera
			glUniform3f(glGetUniformLocation(myShader->ID, "cameraPos"), camera.Position.x, camera.Position.y, camera.Position.z);

			//Set up the objcolor and ambient
			glUniform3f(glGetUniformLocation(myShader->ID, "objColor"), 1.0f, 1.0f, 1.0f);
			glUniform3f(glGetUniformLocation(myShader->ID, "ambientColor"), 0.3f, 0.3f, 0.3f);
			
			//Set up the lights
			SetLight(myShader);

			//Set up the texture
			myShader->SetUniform1i("text_d", Shader::DIFFUSE);
			myShader->SetUniform1i("text_s", Shader::SPECULAR);

			//Set up material
			myMaterial->shader->SetUniform3f("material.ambient", myMaterial->ambient);
			myMaterial->shader->SetUniform1f("material.shininess", myMaterial->shininess);

			//Set Model
			Models[i].Draw(myShader);
		}

		//Deal with event
		glfwPollEvents();
		//Update the camera pos
		camera.UpdateCameraPos();
		//Process keyboard input
		processInput(window);
	}

	glfwTerminate(); //Stop the rander
	return 0;
}

void SetLight(Shader *myShader) {


	//light1 
	if (light1_o == 1)
	{
		//Send the noon light to GPU
		glUniform3f(glGetUniformLocation(myShader->ID, "LightP.lightPos"), light1.position.x, light1.position.y, light1.position.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightP.lightColor"), light1.color.x, light1.color.y, light1.color.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightP.lightDirU"), light1.direction.x, light1.direction.y, light1.direction.z);

		glUniform1f(glGetUniformLocation(myShader->ID, "LightP.constant"), light1.constant);
		glUniform1f(glGetUniformLocation(myShader->ID, "LightP.linear"), light1.linear);
		glUniform1f(glGetUniformLocation(myShader->ID, "LightP.quadratic"), light1.quadratic);
	}
	else {
		//Send the night light to GPU
		glUniform3f(glGetUniformLocation(myShader->ID, "LightP.lightPos"), dark.position.x, dark.position.y, dark.position.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightP.lightColor"), dark.color.x, dark.color.y, dark.color.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightP.lightDirU"), dark.direction.x, dark.direction.y, dark.direction.z);

		glUniform1f(glGetUniformLocation(myShader->ID, "LightP.constant"), dark.constant);
		glUniform1f(glGetUniformLocation(myShader->ID, "LightP.linear"), dark.linear);
		glUniform1f(glGetUniformLocation(myShader->ID, "LightP.quadratic"), dark.quadratic);
	
	}


	//light2
	if (light2_o == 1)
	{
		//Send the pink light to GPU
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS1.lightPos"), light2.position.x, light2.position.y, light2.position.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS1.lightColor"), light2.color.x, light2.color.y, light2.color.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS1.lightDirU"), light2.direction.x, light2.direction.y, light2.direction.z);

		glUniform1f(glGetUniformLocation(myShader->ID, "lightS1.cosPhyInner"), light2.cosPhyInner);
		glUniform1f(glGetUniformLocation(myShader->ID, "lightS1.cosPhyOutter"), light2.cosPhyOutter);
	}
	else {
		//Send the black light to GPU
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS1.lightPos"), black.position.x, black.position.y, black.position.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS1.lightColor"), black.color.x, black.color.y, black.color.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS1.lightDirU"), black.direction.x, black.direction.y, black.direction.z);

		glUniform1f(glGetUniformLocation(myShader->ID, "lightS1.cosPhyInner"), black.cosPhyInner);
		glUniform1f(glGetUniformLocation(myShader->ID, "lightS1.cosPhyOutter"), black.cosPhyOutter);
	
	}
	


	//light3
	if (light3_o == 1)
	{
		//Send the yellow light to GPU
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS2.lightPos"), light3.position.x, light3.position.y, light3.position.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS2.lightColor"), light3.color.x, light3.color.y, light3.color.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS2.lightDirU"), light3.direction.x, light3.direction.y, light3.direction.z);

		glUniform1f(glGetUniformLocation(myShader->ID, "lightS2.cosPhyInner"), light3.cosPhyInner);
		glUniform1f(glGetUniformLocation(myShader->ID, "lightS2.cosPhyOutter"), light3.cosPhyOutter);
	}
	else {
		//Send the black light to GPU
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS2.lightPos"), black.position.x, black.position.y, black.position.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS2.lightColor"), black.color.x, black.color.y, black.color.z);
		glUniform3f(glGetUniformLocation(myShader->ID, "LightS2.lightDirU"), black.direction.x, black.direction.y, black.direction.z);

		glUniform1f(glGetUniformLocation(myShader->ID, "lightS2.cosPhyInner"), black.cosPhyInner);
		glUniform1f(glGetUniformLocation(myShader->ID, "lightS2.cosPhyOutter"), black.cosPhyOutter);
	}
}

unsigned int LoadImageToGPU(const char* filename, GLint internalFormat, GLenum format, int texttureSlot) {

	//Bind the Texture to model
	unsigned int TexBuffer;
	glGenTextures(1, &TexBuffer);
	glActiveTexture(GL_TEXTURE0 + texttureSlot);
	glBindTexture(GL_TEXTURE_2D, TexBuffer);
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
	return TexBuffer;
}

//Return a Model matrix 
glm::mat4 Dealmodel(int i)
{
	//init the model
	glm::mat4 modelMat = glm::mat4(1.0f);
	//Let the fan rotate
	if (i == 8)
	{
		modelMat = glm::translate(glm::mat4(1.0f), objPosition[i]);
		modelMat = glm::rotate(modelMat, 10.2f*(float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
		modelMat = glm::scale(modelMat, objSize[i]);
	}
	//Let the clock rotate
	else if (i == 12) {
		modelMat = glm::translate(glm::mat4(1.0f), objPosition[i]);
		modelMat = glm::rotate(modelMat, 0.2f * (float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));
		modelMat = glm::scale(modelMat, objSize[i]);
	}
	//Open the door
	else if ((doormove == 1) && (i == 15)) {
		doordis += 0.05f;
		modelMat = glm::translate(glm::mat4(1.0f), objPosition[i]);
		modelMat = glm::translate(modelMat, glm::vec3(doordis, 0.0f, 0.0f));
		modelMat = glm::rotate(modelMat, glm::radians(roateAngle[i]), objRoate[i]);
		modelMat = glm::scale(modelMat, objSize[i]);
		if (doordis >= 5.0f)
		{
			doormove = -1;
			doordis = 0;
			objPosition[i].x += 5.0f;
		}
	}
	//close the door
	else if ((doormove == -2) && (i == 15)) {
		doordis -= 0.05f;
		modelMat = glm::translate(glm::mat4(1.0f), objPosition[i]);
		modelMat = glm::translate(modelMat, glm::vec3(doordis, 0.0f, 0.0f));
		modelMat = glm::rotate(modelMat, glm::radians(roateAngle[i]), objRoate[i]);
		modelMat = glm::scale(modelMat, objSize[i]);
		if (doordis <= -5.0f)
		{
			doormove = 0;
			doordis = 0;
			objPosition[i].x -= 5.0f;
		}
	}
	//Close the display
	else if ((screen_o == 0) && (i == 26)) {
		modelMat = glm::mat4(0.0f);
	}
	//Open the display
	else if ((screen_o == 1) && (i == 26)) {
		modelMat = glm::translate(glm::mat4(1.0f), objPosition[i]);
		modelMat = glm::rotate(modelMat, glm::radians(roateAngle[i]), objRoate[i]);
		modelMat = glm::scale(modelMat, objSize[i]);
	}
	//Ratate the cup
	else if ((cup_o == 1) && (i == 33)) {
		if (cup_a > 360)
		{
			cup_a -= 360.f;
		}
		cup_a += 0.02f;
		modelMat = glm::translate(glm::mat4(1.0f), objPosition[i]);
		modelMat = glm::rotate(modelMat, cup_a, glm::vec3(0.0f, 1.0f, 0.0f));
		modelMat = glm::scale(modelMat, objSize[i]);
	}
	//Stop rotate the cup
	else {
		//Set model matrix
		modelMat = glm::translate(glm::mat4(1.0f), objPosition[i]);
		modelMat = glm::rotate(modelMat, glm::radians(roateAngle[i]), objRoate[i]);
		modelMat = glm::scale(modelMat, objSize[i]);
	}
	return modelMat;
}

//Deal with the windows call back
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//Process Mouse
void mouse_callback(GLFWwindow* window, double xPos, double yPos) {

	if (firstMouse == true)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}
	double deltaX, deltaY;
	deltaX = xPos - lastX;
	deltaY = yPos - lastY;

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(deltaX, deltaY);

}

//Process KeyBoard
void processInput(GLFWwindow *window)
{
	//Escape
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	//Rotate the cup
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
	{
		cup_o = 1;
	}
	//Stop rotate the cup
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
	{
		cup_o = 0;
		cup_a = 0.0f;
	}
	//Open the screen
	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
	{
		screen_o = 1;
	}
	//Close the screen
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		screen_o = 0;
	}
	//Close or open the door
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
	{
		if (doormove == 0)
		{
			doormove = 1;
		}
		if (doormove == -1)
		{
			doormove = -2;
		}

	}
	//Turn on or turn off light1
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
	{
			light2_o = 1;
	}

	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
	{
		light2_o = 0;
	}

	//Turn on or turn off light2
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		light3_o = 1;
	}

	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
	{
		light3_o = 0;
	}

	//Switch the night or moon model
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
	{
		light1_o = 1;
	}

	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
	{
		light1_o = 0;
	}

	//Control the camera
	//front or back
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera.speedZ = -0.05f;
	}
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera.speedZ = 0.05f;
	}
	else {
		camera.speedZ = 0.0f;
	}

	//left or right
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera.speedX = -0.05f;
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera.speedX = 0.05f;
	}
	else {
		camera.speedX = 0.0f;
	}

	//up or down
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		camera.speedY = 0.05f;
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		camera.speedY = -0.05f;
	}
	else {
		camera.speedY = 0.0f;
	}
}