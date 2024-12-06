#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits> // For std::numeric_limits

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

    void displayStats() const {
        cout << "\n--- Player Stats ---\n";
        cout << "Current Health: " << currentHealth << "/" << maxHealth << endl;
        cout << "Attack: " << attack << endl;
        cout << "Gold: " << gold << endl;
        cout << "Location: (" << x << ", " << y << ")\n";
        cout << "--------------------\n";
    }

    void move(char direction) {
        switch (direction) {
            case 'w':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y--;
                break;
            case 'd':
                x++;
                break;
        }
    }
};

// Enemy class
class Enemy {
public:
    string name;
    int maxHealth; // Maximum health to reset after encounters
    int health;
    int attack;
    int goldReward;

    Enemy(string n, int h, int a, int reward)
        : name(n), maxHealth(h), health(h), attack(a), goldReward(reward) {}

    void resetHealth() {
        health = maxHealth;
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

// Movement and main game loop
void gameLoop() {
    Character player(50, 10, 20);
    Enemy goblin("Goblin", 30, 5, 5);
    Enemy orc("Orc", 40, 8, 10);
    Enemy dragon("Dragon", 60, 12, 20);

    srand(static_cast<unsigned>(time(0)));

    while (true) {
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
                player.move(command);
                cout << "You moved to (" << player.x << ", " << player.y << ").\n";
                break;
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
