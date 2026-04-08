#include "Mesh.h"
#include <iostream>

// VBO implementation
VBO::VBO(const void* data, size_t size) {
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VBO::~VBO() {
    glDeleteBuffers(1, &m_id);
}

void VBO::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VBO::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// VAO implementation
VAO::VAO() {
    glGenVertexArrays(1, &m_id);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &m_id);
}

void VAO::setVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) const {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}

void VAO::bind() const {
    glBindVertexArray(m_id);
}

void VAO::unbind() const {
    glBindVertexArray(0);
}

// EBO implementation
EBO::EBO(const void* data, size_t size) {
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

EBO::~EBO() {
    glDeleteBuffers(1, &m_id);
}

void EBO::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void EBO::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Mesh::Mesh(const Vertex* vertexData, size_t vertexSize, const void* indexData, size_t indexSize)
    : m_vao(), m_vbo(vertexData, vertexSize), m_ebo(indexData, indexSize),
    m_vertexCount(vertexSize / sizeof(float) / 3), m_indexCount(indexSize / sizeof(unsigned int)) {

    m_vao.bind();
    m_vbo.bind();
    m_ebo.bind();

    m_vao.setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
    m_vao.setVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)3);
    m_vao.setVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, 11 * sizeof(float), (void*)6);
    m_vao.setVertexAttribPointer(3, 3, GL_FLOAT, GL_TRUE, 11 * sizeof(float), (void*)8);

    m_vao.unbind();
}

Mesh::~Mesh() {
}

void Mesh::Draw() const {
    m_vao.bind();
    glDrawElements(GL_TRIANGLES, (GLsizei)m_indexCount, GL_UNSIGNED_INT, 0);
}