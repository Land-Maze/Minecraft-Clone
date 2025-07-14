#ifndef WINDOW_H  
#define WINDOW_H  
#pragma once  

#include <string>  
#include <glad/glad.h>
#include <GLFW/glfw3.h>  

namespace Core {
	class Window {
	public:
		Window();
		~Window();

		bool Initialize();

		void Show();
		void Hide();
		void SetTitle(const std::string& title);
		void Resize(int width, int height);

		int GetWidth() const;
		int GetHeight() const;
		const std::string& GetTitle() const;
		bool IsVisible() const;
		GLFWwindow* GetWindowHandle() const;

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	private:
		std::string m_title;
		int m_width;
		int m_height;
		bool m_visible;
		GLFWwindow* m_windowHandle;
	};
}
#endif