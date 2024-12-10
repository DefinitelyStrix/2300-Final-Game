//
// Created by Henry Cussatt on 12/9/24.
//

#include "Enemy.h"

Enemy::Enemy(int h, int a, int reward) {
    maxHealth = h;
    health = h;
    attack = a;
    goldReward = reward;
}

Enemy::Enemy() {
    maxHealth = 5;
    health = 5;
    attack = 5;
    goldReward = 5;
}

void Enemy::resetHealth() {
    health = maxHealth;
}

