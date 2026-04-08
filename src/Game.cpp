#include <glad/glad.h>
#include "Game.h"
#include "Mesh.h"
#include "Shader.h"
#include <iostream>

Game::Game(int width, int height, const char* title) {
    glfwInit();

    // Create the window
    m_window = new Window(width, height, title);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(m_window->getGLFWwindow(), framebufferSizeCallback);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

Game::~Game() {
    delete m_window;
    glfwTerminate();
}

void Game::run() {

    const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char *fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\0";


    Shader shader(vertexShaderSource, fragmentShaderSource);

    shader.use();

    while (m_window->isOpen()) {
        // Game loop logic goes here
        glClear(GL_COLOR_BUFFER_BIT);

        m_window->swapBuffers();
        glfwPollEvents();
    }
}

void Game::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
