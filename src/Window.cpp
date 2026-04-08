#include "Window.h"
#include <stdexcept>

Window::Window(int width, int height, const char* title) {
    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (m_window == NULL) {
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(m_window);
}

Window::~Window() {
    if (m_window) {
        glfwDestroyWindow(m_window);
    }
}

bool Window::isOpen() const {
    return !glfwWindowShouldClose(m_window);
}

void Window::swapBuffers() const {
    glfwSwapBuffers(m_window);
}