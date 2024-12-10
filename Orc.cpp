//
// Created by Henry Cussatt on 12/9/24.
//

#include "Orc.h"

Orc::Orc(int h, int a, int reward) : Enemy(h, a, reward) {
    name = "Orc";
    maxHealth = h;
    health = h;
    attack = a;
    goldReward = reward;
}

Orc::Orc() : Enemy() {
    name = "Orc";
    maxHealth = 40;
    health = 40;
    attack = 8;
    goldReward = 10;
}