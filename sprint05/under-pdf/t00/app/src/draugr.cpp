#include "draugr.h"

Draugr::Draugr() : m_health(100), m_frostResist(50) {}

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

    if (shoutNumber < 0 || shoutNumber > 8)
        std::cerr << "Invalid shoutNumber" << std::endl;
    else {
        std::cout << "Draugr (" << m_health
                  << " health, " << m_frostResist
                  << "% frost resist) shouts:"
                  << std::endl;
        std::cout << msg[shoutNumber] << std::endl;
    }
}
