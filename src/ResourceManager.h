# ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>

class Shader;
class Mesh;

class ResourceManager {
    public:
        ResourceManager() = delete;
        ~ResourceManager() = delete;

        static Shader LoadShader(const std::string& shaderName);
        static Mesh LoadMesh(const std::string& meshName);

    private:
        static std::string s_basePath;
        static std::string s_shaderPath;
        static std::string s_meshPath;
};

#endif // RESOURCE_MANAGER_H