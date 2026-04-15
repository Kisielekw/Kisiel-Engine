#ifndef COMPONENT_H
#define COMPONENT_H

#include "Mesh.h"
#include "Shader.h"

#include <memory>
#include <glm/glm.hpp>

class Component{
    public:
    enum class Type : uint8_t {
        Transform = 1 << 0,
        Mesh = 1 << 1,
        Material = 1 << 2,
        Camera = 1 << 3,
    };

    Component() = default;
    virtual ~Component() = default;

    virtual Type getType() const = 0;
};

inline Component::Type operator|(const Component::Type& a, const Component::Type& b) {
    return static_cast<Component::Type>(static_cast<int>(a) | static_cast<int>(b));
}

inline Component::Type operator&(const Component::Type& a, const Component::Type& b) {
    return static_cast<Component::Type>(static_cast<int>(a) & static_cast<int>(b));
}

class TransformComponent : public Component {
    public:
    TransformComponent() = default;
    TransformComponent(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
        : m_position(position), m_rotation(rotation), m_scale(scale) {}
    ~TransformComponent() override = default;

    Type getType() const override {
        return Type::Transform;
    }

    glm::mat4 getTransformMatrix() const;
    
    const glm::vec3& getPosition() const;
    const glm::vec3& getRotation() const;
    const glm::vec3& getScale() const;

    void setPosition(const glm::vec3& position);
    void setRotation(const glm::vec3& rotation);
    void setScale(const glm::vec3& scale);

    private:
    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
};

class MeshComponent : public Component {
    public:
    MeshComponent() = default;
    ~MeshComponent() override = default;

    Type getType() const override {
        return Type::Mesh;
    }

    std::shared_ptr<Mesh> getMesh() const;
    void setMesh(std::shared_ptr<Mesh> mesh);

    private:
    std::shared_ptr<Mesh> m_mesh;
};

class MaterialComponent : public Component {
    public:
    MaterialComponent() = default;
    ~MaterialComponent() override = default;

    Type getType() const override {
        return Type::Material;
    }

    std::shared_ptr<Shader> getShader() const;
    void setShader(std::shared_ptr<Shader> shader);

    private:
    std::shared_ptr<Shader> m_shader;
};

class CameraComponent : public Component {
    public:
    CameraComponent() = default;
    ~CameraComponent() override = default;

    Type getType() const override {
        return Type::Camera;
    }

    const glm::mat4 getViewMatrix(const glm::vec3& position, const glm::vec3& rotation) const;
    const glm::mat4& getProjectionMatrix() const;

    void makePerspective(float fov, float aspectRatio, float nearClip, float farClip);
    void makeOrthographic(float left, float right, float bottom, float top, float nearClip, float farClip);

    private:
    glm::mat4 m_projectionMatrix;
};

#endif // COMPONENT_H