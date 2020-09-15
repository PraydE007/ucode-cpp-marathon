#pragma once

#include <iostream>
#include <array>

class Draugr {
public:
    Draugr();

    void shoutPhrase(int shoutNumber) const;

private:
    double m_health;
    const int m_frostResist;
};
