#include "Barrel.h"

Barrel::Barrel() : Container(false, LockpickDifficulty::None) {}

Barrel::~Barrel() {}

std::string Barrel::name() const {
    return "Barrel";
}
