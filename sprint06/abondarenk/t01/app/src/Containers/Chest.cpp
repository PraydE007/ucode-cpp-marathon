#include "Chest.h"

Chest::Chest() : Container(false, LockpickDifficulty::None) {}
Chest::Chest(bool isLocked, const LockpickDifficulty difficulty) : Container(isLocked, difficulty) {}

Chest::~Chest() {}

std::string Chest::name() const {
    return "Chest";
}
