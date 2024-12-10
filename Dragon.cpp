//
// Created by Henry Cussatt on 12/9/24.
//

#include "Dragon.h"

Dragon::Dragon(int h, int a, int reward) : Enemy(h, a, reward) {
    name = "Dragon";
    maxHealth = h;
    health = h;
    attack = a;
    goldReward = reward;
}

Dragon::Dragon() : Enemy() {
    name = "Dragon";
    maxHealth = 80;
    health = maxHealth;
    attack = 15;
    goldReward = 40;
}