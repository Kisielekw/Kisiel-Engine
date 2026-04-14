#include "Entity.h"
#include <glm/gtc/matrix_transform.hpp>

// TransformComponent
glm::mat4 TransformComponent::getTransformMatrix() const {
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), m_position);
    glm::mat4 rotationX = glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
    glm::mat4 rotationY = glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
    glm::mat4 rotationZ = glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.z), glm::vec3(0, 0, 1));
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), m_scale);
    return translation * rotationY * rotationX * rotationZ * scale;
}

const glm::vec3& TransformComponent::getPosition() const {
    return m_position;
}

const glm::vec3& TransformComponent::getRotation() const {
    return m_rotation;
}

const glm::vec3& TransformComponent::getScale() const {
    return m_scale;
}

void TransformComponent::setPosition(const glm::vec3& position) {
    m_position = position;
}

void TransformComponent::setRotation(const glm::vec3& rotation) {
    m_rotation = rotation;
}

void TransformComponent::setScale(const glm::vec3& scale) {
    m_scale = scale;
}

//MeshComponent
std::shared_ptr<Mesh> MeshComponent::getMesh() const {
    return m_mesh;
}

void MeshComponent::setMesh(std::shared_ptr<Mesh> mesh) {
    m_mesh = mesh;
}

//MaterialComponents
std::shared_ptr<Shader> MaterialComponent::getShader() const {
    return m_shader;
}

void MaterialComponent::setShader(std::shared_ptr<Shader> shader) {
    m_shader = shader;
}


//CameraComponent
const glm::mat4 CameraComponent::getViewMatrix(const glm::vec3& position, const glm::vec3& rotation) const {
    glm::vec3 direction = {};
    direction.x = cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
    direction.y = sin(glm::radians(rotation.x));
    direction.z = sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
    return glm::lookAt(position, position + glm::normalize(direction), glm::vec3(0, 1, 0));
}

const glm::mat4& CameraComponent::getProjectionMatrix() const {
    return m_projectionMatrix;
}

void CameraComponent::makePerspective(float fov, float aspectRatio, float nearClip, float farClip) {
    m_projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip);
}

void CameraComponent::makeOrthographic(float left, float right, float bottom, float top, float nearClip, float farClip) {
    m_projectionMatrix = glm::ortho(left, right, bottom, top, nearClip, farClip);
}

//Entity
Entity::Entity() : m_name("Unnamed_Entity"), m_componentMask(Component::Type::Transform) {
    m_components.push_back(std::make_unique<TransformComponent>());
}

Entity::Entity(const std::string& name) : m_name(name), m_componentMask(Component::Type::Transform) {
    m_components.push_back(std::make_unique<TransformComponent>());
}

bool Entity::hasComponents(Component::Type Mask) const {
    return (m_componentMask & Mask) == Mask;
}

const Component::Type& Entity::getMask() const {
    return m_componentMask;
}

void Entity::addChild(const std::shared_ptr<Entity>& child) {
    if(!child) return;
    if(child.get() == this) return;

    for(const auto& existingChild : m_children) {
        if(existingChild == child) return;
    }

    child->m_parent = shared_from_this();
    m_children.push_back(child);
}