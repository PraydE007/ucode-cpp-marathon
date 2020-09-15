#pragma once

#include "../Food/FoodItem.h"

class AbstractWizard {
public:
    AbstractWizard() = default;
    virtual ~AbstractWizard() = default;

    virtual FoodType deductFoodType(FoodItem &food) = 0;
};
