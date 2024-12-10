//
// Created by Henry Cussatt on 12/9/24.
//

#include "Goblin.h"

Goblin::Goblin(int h, int a, int reward) : Enemy(h, a, reward) {
    maxHealth = h;
    health = h;
    attack = a;
    goldReward = reward;
}

Goblin::Goblin() : Enemy() {
    maxHealth = 40;
    health = 40;
    attack = 8;
    goldReward = 10;
}