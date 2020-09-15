#pragma once

#include "FoodItem.h"

class PoisonedFood : public FoodItem {
public:
    PoisonedFood() = default;
    ~PoisonedFood() override;

    FoodType getType() override;
};
