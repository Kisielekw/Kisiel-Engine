#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

const glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(m_position, m_position + m_direction, m_up);
}

const glm::mat4& Camera::getProjectionMatrix() const {
    return m_projMatrix;
}

void Camera::makePerspective(float fov, float aspectRatio, float nearClip, float farClip) {
    m_projMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip);
}

void Camera::makeOrthographic(float left, float right, float bottom, float top, float nearClip, float farClip) {
    m_projMatrix = glm::ortho(left, right, bottom, top, nearClip, farClip);
}


void Camera::setPosition(const glm::vec3& position) {
    m_position = position;
}

void Camera::setLookAt(const glm::vec3& target, const glm::vec3& up) {
    m_direction = glm::normalize(target - m_position);
    m_up = glm::normalize(up);
}

void Camera::rotate(float angle, const glm::vec3& axis) {
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
    m_direction = glm::normalize(glm::vec3(rotation * glm::vec4(m_direction, 0.0f)));
    m_up = glm::normalize(glm::vec3(rotation * glm::vec4(m_up, 0.0f)));
}