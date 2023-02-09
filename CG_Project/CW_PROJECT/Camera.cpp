#include "Camera.h"

//constructor for postion target worldup
Camera::Camera(glm::vec3 postion, glm::vec3 target, glm::vec3 worldup)
{
	Position = postion;
	WorldUp = worldup;
	Forward = glm::normalize(target - postion);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));

}

//constructor for pitch and yaw
Camera::Camera(glm::vec3 postion, float pitch, float yaw, glm::vec3 worldup) 
{
	Position = postion;
	WorldUp = worldup;
	Pitch = pitch;
	Yaw = yaw;
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);		   
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}

// reture the view matrix
glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(Position, Position + Forward, WorldUp);
}

//Update the camera vector
void Camera::UpdateCameraVectores() {
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}

//Deal with the mouse callback
void Camera::ProcessMouseMovement(float deltaX, float deltaY) {
	Pitch -= deltaY * SenceX;
	Yaw -= deltaX * SenceY;
	UpdateCameraVectores();
}

//Update the camera position
void Camera::UpdateCameraPos() {
	Position -= Forward * speedZ + Right * speedX + Up * speedY;
}