#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>

#include "Game.h"

int main(){
    
    Game game(800, 600, "OpenGL Window");
    game.run();
}   