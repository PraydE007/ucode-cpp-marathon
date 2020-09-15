#include "ImperialSoldier.h"

StormcloakSoldier::StormcloakSoldier() {
    m_health = 100;
    m_weapon = NULL;
}

StormcloakSoldier::~StormcloakSoldier() {
    delete m_weapon;
    m_weapon = NULL;
}

void StormcloakSoldier::setWeapon(Axe* sword) {
    delete m_weapon;
    m_weapon = sword;
}

void StormcloakSoldier::attack(ImperialSoldier& enemy) {
    if (m_weapon == NULL)
        return;
    std::cout << "Stormcloak soldier attacks and deals ";
    if (enemy.getHealth() < m_weapon->getDamage())
        std::cout << enemy.getHealth();
    else 
        std::cout << m_weapon->getDamage();
    std::cout << " damage" <<std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void StormcloakSoldier::consumeDamage(int amount) {
    std::cout << "Stormcloak soldier consumes ";
    if (m_health < amount) {
        std::cout << m_health;
        m_health = 0;
    }
    else {
        std::cout << amount;
        m_health -= amount;
    }
    std::cout << " of damage" <<std::endl;
}

int StormcloakSoldier::getHealth() const {
    return m_health;
}
