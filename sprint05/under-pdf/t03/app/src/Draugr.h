#pragma once

#include <iostream>
#include <array>
#include <regex>

class Draugr {
public:
    Draugr();
    Draugr(double health, int frostResist);
    Draugr(int frostResist);

    void shoutPhrase(int shoutNumber) const;
    void setName(const std::string&& name);

private:
    std::string m_name;
    double m_health;
    const int m_frostResist;
};
