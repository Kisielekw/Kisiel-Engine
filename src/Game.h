#ifndef GAME_G
#define GAME_G

#include "Window.h"
#include "Camera.h"

class Game{
    public:
        Game(int width, int height, const char* title);
        ~Game();

        void run();

    private:
        Window* m_window;
        Camera m_camera;
        
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif // GAME_G