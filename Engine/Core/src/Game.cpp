#include<Core/Game.h>
#include<Core/Window.h>

Core::Game::Game() : m_isRunning(false){
	std::cout << "[Core::Game] Game instance created." << std::endl;
}

Core::Game::~Game(){}

bool Core::Game::Initialize() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW\n";
		return false;
	}

	m_window = std::make_unique<Core::Window>();
	if (!m_window->Initialize()) {
		return false;
	}

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

	if(m_window == nullptr) {
		return;
	}
	
	auto windowHandle = m_window->GetWindowHandle();

	while (!glfwWindowShouldClose(windowHandle) && m_isRunning) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(m_window->GetWindowHandle());
		glfwPollEvents();
	}

	m_isRunning = false;
	glfwTerminate();
}
