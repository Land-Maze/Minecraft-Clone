#include <Render/Texture.h>
#include <stb/stb_image.h>

Render::Texture::Texture(const std::string& path) {
	int width, height, channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = Utils::ResourceManager::LoadTexture(path, &width, &height, &channels);
	if (!data) {
		return;
	}

	GLenum format = channels == 4 ? GL_RGBA : GL_RGB;
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);

}


Render::Texture::~Texture() {
	if (m_textureID) {
		glDeleteTextures(1, &m_textureID);
	}
}

void Render::Texture::Bind(GLuint slot) const {
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void Render::Texture::Unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}