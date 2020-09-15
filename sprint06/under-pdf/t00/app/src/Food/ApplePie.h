#pragma once

#include "FoodItem.h"

class ApplePie : public FoodItem {
public:
    ApplePie() = default;
    ~ApplePie() override;

    FoodType getType() override;
};
