//
// Created by Henry Cussatt on 12/9/24.
//

#ifndef INC_2300_FINAL_GAME_ENEMY_H
#define INC_2300_FINAL_GAME_ENEMY_H
#include <string>
using namespace std;

class Enemy {
public:
    string name;
    int maxHealth; // Maximum health to reset after encounters
    int health;
    int attack;
    int goldReward;

    Enemy(int h, int a, int reward);

    Enemy();

    void resetHealth();
};


#endif //INC_2300_FINAL_GAME_ENEMY_H
