#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>

struct Vertex {
    float position[3];
    float color[3];
    float texCoords[2];
    float normal[3];
};

class VBO{
public:
    VBO(const void* data, size_t size);
    ~VBO();

    void bind() const;
    void unbind() const;

 private:
    GLuint m_id;
};

class VAO{
    public:
        VAO();
        ~VAO();

        void setVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) const;
        void bind() const;
        void unbind() const;

    private:
        GLuint m_id;
};

class EBO{
    public:
        EBO(const void* data, size_t size);
        ~EBO();

        void bind() const;
        void unbind() const;

    private:
        GLuint m_id;
};

class Mesh{
    public:
        Mesh(const Vertex* vertexData, size_t vertexSize, const void* indexData, size_t indexSize);
        ~Mesh();

        void Draw() const;
    private:
        VBO m_vbo;
        VAO m_vao;
        EBO m_ebo;
        size_t m_vertexCount;
        size_t m_indexCount;
};

#endif // MESH_H