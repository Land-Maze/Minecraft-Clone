#include <Render/Shader.h>


Render::Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexSource = Utils::ResourceManager::LoadShader(vertexPath);
    if (vertexSource.empty()) {
        return;
    }
    std::string fragmentSource = Utils::ResourceManager::LoadShader(fragmentPath);
    if (fragmentSource.empty()) {
        return;
    }
    m_programID = glCreateProgram();
    if (m_programID == 0) {
        return;
    }
    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

    glAttachShader(m_programID, vertexShader);
    glAttachShader(m_programID, fragmentShader);
    glLinkProgram(m_programID);

    GLint success;
    glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(m_programID, 512, nullptr, infoLog);
        glDeleteProgram(m_programID);
        m_programID = 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    if (m_programID) {
        GLint loc = glGetUniformLocation(m_programID, "uTexture");
        if (loc == -1) {
        }
    }
}

Render::Shader::~Shader() {
    if (m_programID) {
        glDeleteProgram(m_programID);
    }
}

void Render::Shader::Bind() const {
    if (m_programID == 0) {
        return;
    }
    glUseProgram(m_programID);
}

void Render::Shader::Unbind() const {
    glUseProgram(0);
}

void Render::Shader::SetMat4(const std::string& name, const glm::mat4& matrix) const {
    GLint loc = glGetUniformLocation(m_programID, name.c_str());
    if (loc == -1) {
        return;
    }
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Render::Shader::SetInt(const std::string& name, int value) const {
    GLint loc = glGetUniformLocation(m_programID, name.c_str());
    if (loc == -1) {
        return;
    }
    glUniform1i(loc, value);
}

GLuint Render::Shader::CompileShader(GLenum type, const std::string& source) {
    GLuint shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}