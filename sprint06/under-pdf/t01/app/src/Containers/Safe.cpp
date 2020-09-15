#include "Safe.h"

Safe::Safe() : Container(false, LockpickDifficulty::None) {}
Safe::Safe(bool isLocked, const LockpickDifficulty difficulty) : Container(isLocked, difficulty) {}

Safe::~Safe() {}

std::string Safe::name() const {
    return "Safe";
}
