#include <Core/Camera.h>

Core::Camera::Camera(float fov, float aspect, float near, float far)
	: m_fov(fov), m_aspect(aspect), m_near(near), m_far(far) {
	UpdateVectors();
}

void Core::Camera::Update(const Input& input, float deltaTime) {
	float velocity = m_moveSpeed * deltaTime;
	if (input.IsKeyPressed(GLFW_KEY_W)) {
		m_position += m_front * velocity;
	}
	if (input.IsKeyPressed(GLFW_KEY_S)) {
		m_position -= m_front * velocity;
	}
	if (input.IsKeyPressed(GLFW_KEY_A)) {
		m_position -= glm::normalize(glm::cross(m_front, m_up)) * velocity;
	}
	if (input.IsKeyPressed(GLFW_KEY_D)) {
		m_position += glm::normalize(glm::cross(m_front, m_up)) * velocity;
	}

	glm::vec2 mouseDelta = input.GetMouseDelta() * m_mouseSensitivity;
	m_yaw += mouseDelta.x;
	m_pitch -= mouseDelta.y;

	if (m_pitch > 89.0f) m_pitch = 89.0f;
	if (m_pitch < -89.0f) m_pitch = -89.0f;

	UpdateVectors();
}

glm::mat4 Core::Camera::GetViewProjMatrix() const {
	glm::mat4 view = glm::lookAt(m_position, m_position + m_front, m_up);
	glm::mat4 proj = glm::perspective(glm::radians(m_fov), m_aspect, m_near, m_far);
	return proj * view;
}

void Core::Camera::UpdateVectors() {
	glm::vec3 front;
	front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	front.y = sin(glm::radians(m_pitch));
	front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_front = glm::normalize(front);
}