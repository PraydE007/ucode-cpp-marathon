#pragma once

#include "DefinesHeader.h"

class Weapon {
public:
    explicit Weapon(int damage);
    virtual ~Weapon() = default;
    int getDamage() const;

private:
    const int m_damage;
};
