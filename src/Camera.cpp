#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

const glm::mat4& Camera::getViewMatrix() const {
    return m_viewMatrix;
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
    m_viewMatrix = glm::translate(glm::mat4(1.0f), -position);
}

void Camera::setLookAt(const glm::vec3& target, const glm::vec3& up) {
    glm::vec3 position = -glm::inverse(m_viewMatrix)[3];
    m_viewMatrix = glm::lookAt(position, target, up);
}