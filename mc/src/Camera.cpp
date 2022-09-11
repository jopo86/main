#include "Camera.hpp"

Camera::Camera(glm::vec3 pos, float yaw, float pitch, float speed, int sensitivity) : deltaTime(0), lastTime(0), worldUp(glm::vec3(0.0f, 1.0f, 0.0f)) {
	this->pos = pos;
	this->yaw = yaw;
	this->pitch = pitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

	this->speed = speed;
	this->sensitivity = (float)sensitivity / 100;

	update();
}

void Camera::key_control(bool* keys) {
	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP]) {
		pos += front * ((speed * (keys[GLFW_KEY_LEFT_SHIFT] ? 1.5f : 1)) * (keys[GLFW_KEY_LEFT_SHIFT] ? 2 : 1)) * deltaTime;
	}
	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT]) {
		pos -= right * (speed * (keys[GLFW_KEY_LEFT_SHIFT] ? 1.5f : 1)) * deltaTime;
	}
	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN]) {
		pos -= front * (speed * (keys[GLFW_KEY_LEFT_SHIFT] ? 1.5f : 1)) * deltaTime;
	}
	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) {
		pos += right * (speed * (keys[GLFW_KEY_LEFT_SHIFT] ? 1.5f : 1)) * deltaTime;
	}
	if (keys[GLFW_KEY_SPACE]) {
		pos += worldUp * (speed * (keys[GLFW_KEY_LEFT_SHIFT] ? 1.5f : 1)) * deltaTime;
	}
	if (keys[GLFW_KEY_C] || keys[GLFW_KEY_LEFT_CONTROL]) {
		pos -= worldUp * (speed * (keys[GLFW_KEY_LEFT_SHIFT] ? 1.5f : 1)) * deltaTime;
	}
}

void Camera::mouse_control(double x, double y) {
	float change_x = x - mouse_last_x;
	float change_y = y - mouse_last_y;
	mouse_last_x = x;
	mouse_last_y = y;

	change_x *= sensitivity;
	change_y *= sensitivity;

	yaw += change_x;
	pitch -= change_y;

	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;

	update();
}

glm::mat4 Camera::get_view_matrix() {
	return glm::lookAt(pos, pos + front, up);
}

void Camera::update() {
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));

	deltaTime = glfwGetTime() - lastTime;
	lastTime = glfwGetTime();
}

Camera::~Camera() {

}