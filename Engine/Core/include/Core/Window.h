#ifndef WINDOW_H  
#define WINDOW_H  
#pragma once  

#include <string>  
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Input.h"
#include <memory>

namespace Core {
	class Window {
	public:
		Window();
		~Window();

		bool Initialize();
		void SetInput(std::shared_ptr<Input> m_input);

		void Show();
		void Hide();
		void SetTitle(const std::string& title);
		void Resize(int width, int height);

		int GetWidth() const;
		int GetHeight() const;
		const std::string& GetTitle() const;
		bool IsVisible() const;
		GLFWwindow* GetWindowHandle() const;

		bool ShouldClose() const;
		void PollEvents();
		void SwapBuffers();
		void Shutdown();

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	private:
		std::string m_title;
		int m_width;
		int m_height;
		bool m_isVisible;
		bool m_isMouseUnlocked; // This is when user wants to press on UI elements
		GLFWwindow* m_windowHandle;
		std::shared_ptr<Input> m_input;
	};
}
#endif