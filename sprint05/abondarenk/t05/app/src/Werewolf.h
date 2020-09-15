#pragma once

#include "Wolf.h"
#include "Human.h"

class Werewolf final : public Wolf, public Human {
public:
    Werewolf();
    ~Werewolf();
};
