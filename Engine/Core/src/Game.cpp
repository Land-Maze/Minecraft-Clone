#include<Core/Game.h>

Core::Game::Game() : m_isRunning(false){}

bool Core::Game::Initialize() {
	m_input = std::make_shared<Core::Input>();
	m_window = std::make_unique<Core::Window>();
	m_renderer = std::make_unique<Render::Renderer>();

	if (!m_window->Initialize()) {
		return false;
	}

	int width, height;
	m_window->GetWindowSize(width, height);
	m_camera = std::make_unique<Camera>(45.0f, static_cast<float>(width) / height, 0.1f, 100.0f);

	m_window->SetInput(m_input);

	glfwMakeContextCurrent(m_window->GetWindowHandle());

	if (!Core::GLADLoader::loadGLAD()) {
		return false;
	}

	// Setting Window viewport and callback for resizing
	glViewport(0, 0, m_window->GetWidth(), m_window->GetHeight());
	glfwSetFramebufferSizeCallback(m_window->GetWindowHandle(), m_window->framebuffer_size_callback);

	if (!m_renderer->Initialize()) {
		return false;
	}

	m_isRunning = true;
	return true;
}

void Core::Game::Shutdown() {
	m_isRunning = false;
}

void Core::Game::Run() {
	double lastTime = glfwGetTime();
	while (!m_window->ShouldClose() && m_isRunning) {
		double currentTime = glfwGetTime();
		float deltaTime = static_cast<float>(currentTime - lastTime);
		lastTime = currentTime;

		m_window->PollEvents();

		if (m_input->IsKeyPressed(GLFW_KEY_ESCAPE)) {
			Core::Game::Shutdown();
		}

		m_renderer->Render(m_camera->GetViewProjMatrix());
		
		m_camera->Update(*m_input, deltaTime);
		m_input->Update();

		m_window->SwapBuffers();
	}
}