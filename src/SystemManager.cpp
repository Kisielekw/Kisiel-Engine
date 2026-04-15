#include "SystemManager.h"

void SystemManager::runSystems() {
    for (const auto& system : m_systems) {
        system->Action();
    }
}