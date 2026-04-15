# ifndef ENTITY_H
# define ENTITY_H

#include "Component.h"

#include <vector>
#include <string>
#include <memory>
#include <glm/glm.hpp>

class Entity : public std::enable_shared_from_this<Entity> {
    public:
    Entity();
    Entity(const std::string& name);
    ~Entity() = default;

    template<typename T, typename... Args>
    void addComponent(Args&&... args) {
        std::shared_ptr<T> component = std::make_shared<T>(std::forward<Args>(args)...);
        m_componentMask = m_componentMask | component->getType();
        m_components.push_back(component);
    }
    
    template<typename T>
    std::shared_ptr<Component> getComponent() const {
        if(!hasComponents(T().getType())) {
            return nullptr;
        }
    
        for (const auto& component : m_components) {
            if (component->getType() == T().getType()) {
                return component;
            }
        }
        return nullptr;
    }

    bool hasComponents(Component::Type Mask) const;
    const Component::Type& getMask() const;

    void addChild(const std::shared_ptr<Entity>& child);

    private:
    std::string m_name;
    std::weak_ptr<Entity> m_parent;
    std::vector<std::shared_ptr<Entity>> m_children;
    std::vector<std::shared_ptr<Component>> m_components;

    Component::Type m_componentMask;
};

# endif // ENTITY_H