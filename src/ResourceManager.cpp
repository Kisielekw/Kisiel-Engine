#include "ResourceManager.h"
#include "Shader.h"
#include "Mesh.h"
#include <format>
#include <fstream>
#include <iostream>

std::string ResourceManager::s_basePath = "Assets/";
std::string ResourceManager::s_shaderPath = "Shaders/";
std::string ResourceManager::s_meshPath = "Meshes/";

Shader ResourceManager::LoadShader(const std::string& shaderName) {
    std::ifstream vertexFile(s_basePath + s_shaderPath + shaderName + ".vert");
    if (!vertexFile) {
        std::cerr << "Vertex shader file not found: " << shaderName << ".vert" << std::endl;
        return Shader("", "");
    }

    std::ifstream fragmentFile(s_basePath + s_shaderPath + shaderName + ".frag");
    if (!fragmentFile) {
        std::cerr << "Fragment shader file not found: " << shaderName << ".frag" << std::endl;
        return Shader("", "");
    }

    std::string vertexSource((std::istreambuf_iterator<char>(vertexFile)), std::istreambuf_iterator<char>());
    std::string fragmentSource((std::istreambuf_iterator<char>(fragmentFile)), std::istreambuf_iterator<char>());

    return Shader(vertexSource, fragmentSource);
}

Mesh ResourceManager::LoadMesh(const std::string& meshName) {
    // For simplicity, we will just return a dummy mesh here.
    // In a real implementation, you would read the mesh data from a file.
    Vertex vertices[] = {
        {{0.0f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}
    };
    unsigned int indices[] = { 0, 1, 2 };
    return Mesh(vertices, sizeof(vertices), indices, sizeof(indices));
}