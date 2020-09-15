#pragma once

#include "FoodItem.h"

class SweetRoll : public FoodItem {
public:
    SweetRoll() = default;
    ~SweetRoll() override;

    FoodType getType() override;
};
