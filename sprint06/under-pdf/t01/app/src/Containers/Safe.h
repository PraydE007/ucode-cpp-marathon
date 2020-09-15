#pragma once

#include "Container.h"

class Safe : public Container {
public:
    Safe();
    Safe(bool isLocked, const LockpickDifficulty difficulty);
    ~Safe() override;

    std::string name() const override;
};
