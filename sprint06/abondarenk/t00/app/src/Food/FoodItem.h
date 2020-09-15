#pragma once

#include "FoodType.h"

class FoodItem {
public:
    FoodItem() = default;
    virtual ~FoodItem() = default;

    virtual FoodType getType();
};
