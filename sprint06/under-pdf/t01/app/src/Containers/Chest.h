#pragma once

#include "Container.h"

class Chest : public Container {
public:
    Chest();
    Chest(bool isLocked, const LockpickDifficulty difficulty);
    ~Chest() override;

    std::string name() const override;
};
