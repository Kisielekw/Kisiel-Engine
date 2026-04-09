#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera{
    public:
        Camera() = default;
        ~Camera() = default;

        const glm::mat4 getViewMatrix() const;
        const glm::mat4& getProjectionMatrix() const;

        void makePerspective(float fov, float aspectRatio, float nearClip, float farClip);
        void makeOrthographic(float left, float right, float bottom, float top, float nearClip, float farClip);

        void setPosition(const glm::vec3& position);
        void setLookAt(const glm::vec3& target, const glm::vec3& up);

        void rotate(float angle, const glm::vec3& axis);

    private:
        glm::mat4 m_projMatrix;
        glm::vec3 m_position;
        glm::vec3 m_direction;
        glm::vec3 m_up;

};

#endif