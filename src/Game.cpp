#include <iostream>
#include <glad/glad.h>
#include "Game.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "Mesh.h"

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
    Mesh mesh = ResourceManager::LoadMesh("triangle");

    Shader shader = ResourceManager::LoadShader("flatColour");

    shader.use();

    while (m_window->isOpen()) {
        // Game loop logic goes here
        glClear(GL_COLOR_BUFFER_BIT);

        mesh.Draw();

        m_window->swapBuffers();
        glfwPollEvents();
    }
}

void Game::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
