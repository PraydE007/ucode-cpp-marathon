#pragma once

#include "Container.h"

class Barrel : public Container {
public:
    Barrel();
    ~Barrel() override;

    std::string name() const override;
};
