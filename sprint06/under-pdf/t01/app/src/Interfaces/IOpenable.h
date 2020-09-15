#pragma once

#include "Containers/LockpickDifficulty.h"

class IOpenable {
public:
    virtual bool tryToOpen(LockpickDifficulty skill) = 0;
};
