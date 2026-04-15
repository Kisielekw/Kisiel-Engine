#include "Entity.h"

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