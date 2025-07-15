#include <Render/Renderer.h>

Render::Renderer::Renderer() = default;

Render::Renderer::~Renderer() {
	Shutdown();
}

bool Render::Renderer::Initialize() {
	m_blockShader = std::make_unique<Shader>("Assets/shaders/block.vert", "Assets/shaders/block.frag");
	m_blockTexture = std::make_unique<Texture>("Assets/textures/uv_test.png");

	std::vector<Vertex> vertices = {
		// FIXME: Extract it to separate class
		{{ -0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f }},
		{{  0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f }},
		{{  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f }},
		{{ -0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f }},

		{{ -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }},
		{{  0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }},
		{{  0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }},
		{{ -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }},

		{{ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }},
		{{ -0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f }},
		{{ -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f }},
		{{ -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }},

		{{  0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f }},
		{{  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }},
		{{  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }},
		{{  0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f }},

		{{ -0.5f,  0.5f,  0.5f }, { 0.0f, 0.0f }},
		{{  0.5f,  0.5f,  0.5f }, { 1.0f, 0.0f }},
		{{  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f }},
		{{ -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f }},

		{{ -0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f }},
		{{  0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f }},
		{{  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f }},
		{{ -0.5f, -0.5f,  0.5f }, { 0.0f, 1.0f }}
	};

	std::vector<GLuint> indices = {

		0, 1, 2, 2, 3, 0,

		4, 5, 6, 6, 7, 4,

		8, 9, 10, 10, 11, 8,

		12, 13, 14, 14, 15, 12,

		16, 17, 18, 18, 19, 16,

		20, 21, 22, 22, 23, 20
	};

	m_blockMesh = std::make_unique<Mesh>(vertices, indices);

	glEnable(GL_DEPTH_TEST);

	return true;
}

void Render::Renderer::Render(const glm::mat4& viewProjMatrix) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	m_blockShader->Bind();
	m_blockTexture->Bind(0);
	m_blockShader->SetInt("uTexture", 0);
	m_blockShader->SetMat4("uViewProj", viewProjMatrix);
	m_blockShader->SetMat4("uModel", glm::mat4(1.0f));

	m_blockMesh->Draw();

	m_blockShader->Unbind();
	m_blockTexture->Unbind();

	GLenum err;
	if ((err = glGetError()) != GL_NO_ERROR) {
		// FIXME: Put the log here
	}

}

void Render::Renderer::Shutdown() {
	m_blockTexture.reset();
	m_blockShader.reset();
}