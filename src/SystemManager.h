#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "System.h"

#include <vector>
#include <memory>

class SystemManager {
    public:
        SystemManager() = default;
        ~SystemManager() = default;

        void runSystems();

        template<typename T, typename... Args>
        void addSystem(Args&&... args) {
            std::shared_ptr<T> system = std::make_shared<T>(std::forward<Args>(args)...);
            m_systems.push_back(system);
        }

    private:

    std::vector<std::shared_ptr<System>> m_systems;
};

#endif // SYSTEM_MANAGER_H