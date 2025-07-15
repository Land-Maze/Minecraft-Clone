#include<Core/Game.h>
#include<Core/Window.h>

Core::Game::Game() : m_isRunning(false){
	std::cout << "[Core::Game] Game instance created." << std::endl;
}

bool Core::Game::Initialize() {
	m_input = std::make_shared<Core::Input>();
	m_window = std::make_unique<Core::Window>();
	
	if (!m_window->Initialize()) {
		return false;
	}

	m_window->SetInput(m_input);

	glfwMakeContextCurrent(m_window->GetWindowHandle());

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n" << std::endl;
		return false;
	}

	// Setting Window viewport and callback for resizing
	glViewport(0, 0, m_window->GetWidth(), m_window->GetHeight());
	glfwSetFramebufferSizeCallback(m_window->GetWindowHandle(), m_window->framebuffer_size_callback);

	std::cout << "[Core::Game] Game initialized successfully." << std::endl;
	m_isRunning = true;
	return true;
}

void Core::Game::Shutdown() {
	m_isRunning = false;
}

void Core::Game::Run() {
    while (!m_window->ShouldClose() && m_isRunning) {
        m_window->PollEvents();

		// NOTE: This is just for test, I will delete it when I will introduce Camera class
        if (m_input->IsKeyPressed(GLFW_KEY_W)) {
            std::cout << "W" << std::endl;
        }
        if (m_input->IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            std::cout << "Left mouse" << std::endl;
        }

        m_window->SwapBuffers();
    }
}