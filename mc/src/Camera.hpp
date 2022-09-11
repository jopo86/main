#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	Camera(){}
	Camera(glm::vec3 pos, float yaw, float pitch, float speed, int sensitivity);

	void key_control(bool* keys);
	void mouse_control(double x, double y);

	glm::mat4 get_view_matrix();

	~Camera();

private:
	glm::vec3 pos;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	float mouse_last_x;
	float mouse_last_y;

	float yaw;
	float pitch;
	float speed;
	float sensitivity;

	float deltaTime;
	float lastTime;

	void update();
};

