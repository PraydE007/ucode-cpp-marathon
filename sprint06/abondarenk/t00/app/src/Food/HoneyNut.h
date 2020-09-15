#pragma once

#include "FoodItem.h"

class HoneyNut : public FoodItem {
public:
    HoneyNut() = default;
    ~HoneyNut() override;

    FoodType getType() override;
};
