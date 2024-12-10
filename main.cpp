#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <list>
#include <limits> // For std::numeric_limits
#include "Enemy.h"
#include "Orc.h"

using namespace std;

// Character class
class Character {
public:
    int maxHealth;
    int currentHealth;
    int attack;
    int gold;
    int x, y; // Coordinates

    Character(int health, int atk, int startGold)
        : maxHealth(health), currentHealth(health), attack(atk), gold(startGold), x(0), y(0) {}

    void heal() {
        currentHealth = maxHealth;
        cout << "You are fully healed!" << endl;
    }

    void setPos(int xPos, int yPos) {
        x = xPos;
        y = yPos;
    }

    void displayStats() const {
        cout << "\n--- Player Stats ---\n";
        cout << "Current Health: " << currentHealth << "/" << maxHealth << endl;
        cout << "Attack: " << attack << endl;
        cout << "Gold: " << gold << endl;
        cout << "Location: (" << x << ", " << y << ")\n";
        cout << "--------------------\n";
    }

    bool move(char direction, string map[9][9]) {
        switch (direction) {
            case 'w':
                cout << map[x][y] << endl;
                if (map[x][y].find('0') < map[x][y].length()) {
                    y--;
                    return true;
                }
                return false;
            case 'a':
                if (map[x][y].find('2') < map[x][y].length()) {
                    x--;
                    return true;
                }
                return false;
            case 's':
                if (map[x][y].find('1') < map[x][y].length()) {
                    y++;
                    return true;
                }
                return false;
            case 'd':
                if (map[x][y].find('3') < map[x][y].length()) {
                    x++;
                    return true;
                }
                return false;
        }
        return false;
    }
};


// Shop function
void shop(Character& player) {
    cout << "\nWelcome to the shop! Choose an option:\n";
    cout << "1. Increase Attack (Cost: 10 gold)\n";
    cout << "2. Increase Max Health (Cost: 10 gold)\n";
    cout << "3. Heal (Cost: 5 gold)\n";
    cout << "4. Leave Shop\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1:
            if (player.gold >= 10) {
                player.attack += 5;
                player.gold -= 10;
                cout << "Attack increased by 5!" << endl;
            } else {
                cout << "Not enough gold!" << endl;
            }
            break;
        case 2:
            if (player.gold >= 10) {
                player.maxHealth += 10;
                player.currentHealth = player.maxHealth;
                player.gold -= 10;
                cout << "Max Health increased by 10!" << endl;
            } else {
                cout << "Not enough gold!" << endl;
            }
            break;
        case 3:
            if (player.gold >= 5) {
                player.currentHealth = player.maxHealth;
                player.gold -= 5;
                cout << "You are fully healed!" << endl;
            } else {
                cout << "Not enough gold!" << endl;
            }
            break;
        case 4:
            cout << "You left the shop.\n";
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}

// Combat system
void combat(Character& player, Enemy& enemy) {
    enemy.resetHealth(); // Reset enemy health before the encounter
    cout << "\nYou encountered a " << enemy.name << "!\n";

    while (player.currentHealth > 0 && enemy.health > 0) {
        cout << "Your turn! Choose an action:\n";
        cout << "1. Attack\n";
        cout << "2. Defend\n";
        cout << "3. Run\n";
        int action;
        cin >> action;

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (action == 1) {
            enemy.health -= player.attack;
            cout << "You attacked the enemy for " << player.attack << " damage!\n";
        } else if (action == 2) {
            cout << "You defended, reducing incoming damage by 50% next turn!\n";
        } else if (action == 3) {
            if (rand() % 100 < 80) {
                cout << "You successfully ran away!\n";
                return;
            } else {
                cout << "Failed to escape!\n";
            }
        }

        if (enemy.health > 0) {
            cout << "Enemy's turn!\n";
            int damage = action == 2 ? enemy.attack / 2 : enemy.attack;
            player.currentHealth -= damage;
            cout << "Enemy dealt " << damage << " damage to you!\n";
        }
    }

    if (player.currentHealth <= 0) {
        cout << "You were defeated!\n";
    } else {
        cout << "You defeated the " << enemy.name << "!\n";
        player.gold += enemy.goldReward;
        cout << "You earned " << enemy.goldReward << " gold!\n";
    }
}

// Draw current tile
void drawRoom(string map) {
    string leftWall = "|";
    string leftDoor = "|";
    string rightDoor = "|";
    string rightWall = "|";
    string upDoor = "-";
    string upWall = "-";
    string downWall = "-";
    string downDoor = "-";
    string blank = "";

    if (map.find('0') < map.length()) {
        upDoor = "X";
    }
    if (map.find('1') < map.length()) {
        downDoor = "X";
    }
    if (map.find('2') < map.length()) {
        leftDoor = "X";
    }
    if (map.find('3') < map.length()) {
        rightDoor = "X";
    }

    cout << upWall << upWall << upWall;
    cout << upDoor << upDoor << upDoor;
    cout << upWall << upWall << upWall << endl;
    cout << leftWall << "       " << rightWall << endl;
    cout << leftWall << "       " << rightWall << endl;
    cout << leftDoor << "       " << rightDoor << endl;
    cout << leftDoor << "       " << rightDoor << endl;
    cout << leftDoor << "       " << rightDoor << endl;
    cout << leftWall << "       " << rightWall << endl;
    cout << leftWall << "       " << rightWall << endl;
    cout << downWall << downWall << downWall;
    cout << downDoor << downDoor << downDoor;
    cout << downWall << downWall << downWall << endl;


}

// Movement and main game loop
void gameLoop() {
    Character player(50, 10, 20);
//    Enemy goblin("Goblin", 30, 5, 5);
    Orc orc;
//    Enemy dragon("Dragon", 60, 12, 20);
    string map[9][9];
    ifstream f("../map1.txt");
    string line;
    int col = 0;
    int row = 0;
    string growth;
    bool startPicked = false;
    int startX;
    int startY;

    // Iterates through map.txt, created coordinate matrix
    while (getline(f, line)) {
        row = 0;
        growth = "";
        for (char c: line) {
            // 9 represents empty space
            if (c == '9') {
                map[row][col] = "9";
                row++;
            }
            // concatenates all room openings into single string
            else if (c != '(' && c != ')') {
                growth += c;
            }
            // marks end of room openings
            // continues onto next value
            else if (c == ')') {
                if (!startPicked) {
                    startX = row;
                    startY = col;
                    startPicked = true;
                    player.setPos(startX,startY);
                }
                map[row][col] = growth;
                row++;
                growth = "";
            }
        }
        col++;
    }

    srand(static_cast<unsigned>(time(0)));

    while (true) {
        drawRoom(map[player.x][player.y]);
        cout << "\nMove your character (W/A/S/D). Press SPACE to view stats. Press Q to quit.\n";

        // Read single character input including space
        char command;
        cin.get(command);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool skipRandomEvents = false; // Flag to skip random events after showing stats

        switch (command) {
            case 'w':
            case 'a':
            case 's':
            case 'd':
                if (player.move(command, map)) {
                    cout << "You moved to (" << player.x << ", " << player.y << ").\n";
                    break;
                }
                else {
                    cout << "Invalid movement" << endl;
                    skipRandomEvents = true;
                    break;
                }
            case ' ':
                player.displayStats();
                skipRandomEvents = true; // Skip random events after stats
                break;
            case 'q':
                cout << "Exiting game...\n";
                return;
            default:
                cout << "Invalid command!\n";
                skipRandomEvents = true; // Skip random events for invalid input
        }

        if (skipRandomEvents) {
            continue; // Skip to the next loop iteration
        }

        // Random encounter
        if (rand() % 5 == 0) {
            int encounterChance = rand() % 100;
            if (encounterChance < 60) {
                combat(player, goblin);
            } else if (encounterChance < 90) {
                combat(player, orc);
            } else {
                combat(player, dragon);
            }
        }

        // Random shop
        if (rand() % 10 == 0) {
            shop(player);
        }
    }
}


int main() {

    gameLoop();
    return 0;
}
