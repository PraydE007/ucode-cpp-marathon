#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier() {
    m_health = 100;
    m_weapon = NULL;
}

ImperialSoldier::~ImperialSoldier() {
    delete m_weapon;
    m_weapon = NULL;
}

void ImperialSoldier::setWeapon(Sword* sword) {
    delete m_weapon;
    m_weapon = sword;
}

void ImperialSoldier::attack(StormcloakSoldier& enemy) {
    if (m_weapon == NULL)
        return;
    std::cout << "Imperial soldier attacks and deals ";
    if (enemy.getHealth() < m_weapon->getDamage())
        std::cout << enemy.getHealth();
    else
        std::cout << m_weapon->getDamage();
    std::cout << " damage" <<std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void ImperialSoldier::consumeDamage(int amount) {
    std::cout << "Imperial soldier consumes ";
    if (m_health < amount) {
        std::cout << m_health;
        m_health = 0;
    }
    else {
        std::cout << amount;
        m_health -= amount;
    }
    std::cout << " of damage";
    if (m_health <= 0)
        std::cout << " and dies" << std::endl;
    else
        std::cout << std::endl;
}

int ImperialSoldier::getHealth() const {
    return m_health;
}
