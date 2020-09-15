#include "MightyWizard.h"

void MightyWizard::checkFood(FoodItem& food) {
    FoodType foods = deductFoodType(food);

    if (foods == FoodType::ApplePie)
        std::cout << "Apple pie. Ugh, not again!" << std::endl;
    else if (foods == FoodType::HoneyNut)
        std::cout << "Honey nut. Mmm, tasty!" << std::endl;
    else if (foods == FoodType::SweetRoll)
        std::cout << "SweetRoll. Mmm, tasty!" << std::endl;
    else if (foods == FoodType::PoisonedFood)
        std::cout << "Poison. Ugh, not again!" << std::endl;
    else
        std::cout << "<unknown. Ugh, not again!" << std::endl;
}

void MightyWizard::checkFood(FoodItem*& food) {
    checkFood(*food);
}


FoodType MightyWizard::deductFoodType(FoodItem& food) {
    return food.getType();
}

void MightyWizard::checkFood(std::nullptr_t nu) {
    (void)nu;
    std::cout << "<unknown>. Ugh, not again!" << std::endl;
}

MightyWizard::MightyWizard(std::string names) {
    m_name = names;
}

MightyWizard::~MightyWizard() {}
