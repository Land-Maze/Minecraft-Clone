#ifndef CAMERA_H
#define CAMERA_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Core/Input.h>

namespace Core {
	class Camera {
	public:
		Camera(float fov = 45.0f, float aspect = 800.0f / 600.0f, float near = 0.1f, float far = 100.0f);
		~Camera() = default;

		void Update(const Input& input, float deltaTime);
		glm::mat4 GetViewProjMatrix() const;

	private:
		glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 2.0f);
		float m_yaw = -90.0f;
		float m_pitch = 0.0f;
		glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);

		float m_fov;
		float m_aspect;
		float m_near;
		float m_far;

		float m_moveSpeed = 5.0f;
		float m_mouseSensitivity = 0.05f;

		void UpdateVectors();
	};

}

#endif