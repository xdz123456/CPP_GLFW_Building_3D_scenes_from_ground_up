#pragma once
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 postion, glm::vec3 target, glm::vec3 worldup);
	Camera(glm::vec3 postion, float pitch, float yaw, glm::vec3 worldup);
	glm::vec3 Position;
	glm::vec3 Forward;
	glm::vec3 Right;
	glm::vec3 Up;
	glm::vec3 WorldUp;
	glm::mat4 GetViewMatrix();
	float Pitch;
	float Yaw;
	float SenceX = 0.002;
	float SenceY = 0.002;
	float speedZ = 0;
	float speedX = 0;
	float speedY = 0;
	void ProcessMouseMovement(float deltaX, float deltaY);
	void UpdateCameraPos();
private:
	void UpdateCameraVectores();
	
};

