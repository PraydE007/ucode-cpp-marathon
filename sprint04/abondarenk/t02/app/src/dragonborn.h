#pragma once

#define USAGE "usage: ./dragonborn [action]"
#define INV_ACTION "Invalid action"

#include <map>
#include <iostream>
#include <functional>

class Dragonborn final {
public:
    enum class Actions{
        Shout,
        Magic,
        Weapon,
        Invalid
    };

    void executeAction(const Actions action);

private:
    void shoutThuum() const;
    void attackWithMagic() const;
    void attackWithWeapon() const;
};
