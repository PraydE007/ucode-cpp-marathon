#pragma once

#include <iostream>
#include "AbstractWizard.h"

class MightyWizard final : public AbstractWizard {
public:
    MightyWizard(std::string names);
    ~MightyWizard() override;

    FoodType deductFoodType(FoodItem &food) override;
    void checkFood(std::nullptr_t nu);
    void checkFood(FoodItem &food);
    void checkFood(FoodItem*& food);
private:
    std::string m_name;
};
