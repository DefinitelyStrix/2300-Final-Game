//
// Created by Henry Cussatt on 12/9/24.
//

#include "Goblin.h"

Goblin::Goblin(int h, int a, int reward) : Enemy(h, a, reward) {
    name = "Goblin";
    maxHealth = h;
    health = h;
    attack = a;
    goldReward = reward;
}

Goblin::Goblin() : Enemy() {
    name = "Goblin";
    maxHealth = 20;
    health = 40;
    attack = 4;
    goldReward = 5;
}