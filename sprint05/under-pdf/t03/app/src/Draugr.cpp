#include "Draugr.h"

Draugr::Draugr(double health, int frostResist) : m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr with " << m_health
              << " and " << m_frostResist
              << "% frost resist was born!" << std::endl;
}
Draugr::Draugr(int frostResist) : Draugr(100, frostResist) {}
Draugr::Draugr() : Draugr(100, 50) {}

void Draugr::shoutPhrase(int shoutNumber) const {
    std::array<std::string, 9> msg = {
        "Qiilaan Us Dilon!",
        "Bolog Aaz, Mal Lir!",
        "Kren Sosaal!",
        "Dir Volaan!",
        "Aar Vin Ok!",
        "Unslaad Krosis!",
        "Faaz! Paak! Dinok!",
        "Aav Dilon!",
        "Sovngarde Saraan!"
    };

    if (shoutNumber < 0 || shoutNumber > 8) {
        std::cerr << "Invalid shoutNumber" << std::endl;
        std::exit(1);
    }
    else {
        std::cout << "Draugr (" << m_health
                << " health, " << m_frostResist
                << "% frost resist) shouts:"
                << std::endl;
        std::cout << msg[shoutNumber] << std::endl;
    }
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}
