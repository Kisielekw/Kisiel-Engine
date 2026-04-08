#ifndef WINDOW_H
#define WINDOW_H

#include <glfw/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool isOpen() const;
    void swapBuffers() const;
    GLFWwindow* getGLFWwindow() const { return m_window; }

private:
    GLFWwindow* m_window;
};

#endif // WINDOW_H