#ifndef SYSTEM_H
#define SYSTEM_H

#include "Component.h"

class System{
public:
    System() = default;
    virtual ~System() = default;

    virtual void Action() = 0;

private:
    Component::Type m_requiredComponents;
};

#endif // SYSTEM_H