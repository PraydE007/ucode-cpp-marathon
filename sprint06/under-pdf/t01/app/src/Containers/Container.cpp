#include "Container.h"

Container::Container(bool isLocked, const LockpickDifficulty difficulty) {
    m_isLocked = isLocked;
    m_difficulty = difficulty;
}

LockpickDifficulty Container::lockDifficulty() const {
    return m_difficulty;
}

bool Container::isLocked() const {
    return m_isLocked;
}

bool Container::tryToOpen(LockpickDifficulty skill) {
    if (int(skill) >= int(m_difficulty) || !m_isLocked)
        return true;
    else
        return false;
}
