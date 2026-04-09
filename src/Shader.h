#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

class Shader {
public:
    Shader(const std::string& vertexSource, const std::string& fragmentSource);
    ~Shader();

    void use() const;
    
    void setUniform(const std::string& name, const int& value) const;
    void setUniform(const std::string& name, const float& value) const;
    void setUniform(const std::string& name, const glm::vec3& value) const;
    void setUniform(const std::string& name, const glm::mat4& value) const;

private:
    GLuint m_id;
};

#endif // SHADER_H