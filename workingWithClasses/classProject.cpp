//Option 1: Text-Based RPG Battle (The "Class" Project)
//The Concept: Object-Oriented Programming (Classes & Objects). Why: In Hangman, you had lives and guesses floating around in main. In a real C++ program, you want to bundle data and behavior together.
//The Project: Create a simple 1v1 battle simulator (like Pokémon or Final Fantasy). You need a Player and an Enemy. They take turns attacking until one dies.
//New Things You Will Learn:
//Classes: Creating a class Character.
//Encapsulation: keeping health private and only changing it via a public function takeDamage(int amount).
//Constructors: Setting up the character's name and max health when the object is created.
//RNG: Better random number generation for damage variance (e.g., hitting for 5-10 damage).
//Spicy Twist (For the brave): Implement Inheritance. Make a base class Entity, then have Player and Goblin inherit from it.

#include <string>
#include <iostream>
#include <random>

class Entity {
public:
    // Constructor to initialize name and max health
    Entity(std::string inputName, int inputMaxHealth) : name(inputName), max_health(inputMaxHealth), health(inputMaxHealth) {}

    // Method to take damage
    void takeDamage(int damage) {
        if (damage > 0) {
            health -= damage;
            if (health < 0) {
                health = 0;
            }
        }
    }

    int attack(){
        static std::mt19937 rng{std::random_device{}()};
        std::uniform_int_distribution<> dist(0,3);
        return dist(rng);
    }

    // Getters for name and health
    std::string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getMaxHealth() const {
        return max_health;
    }

private:
    int max_health;
    int health;
    std::string name;
};

class Player : public Entity {
public:
    // Constructor for Player class
    Player(std::string inputName, int inputMaxHealth) : Entity(inputName, inputMaxHealth) {}
};

int main() {
    //Test Player
    Player player("Hero", 10);

    //get player health
    std::cout << player.getHealth() << '\n';

    //test output
    std::cout << player.getName() << " has " << player.getHealth() << "/" << player.getMaxHealth() << " health." << std::endl;

    player.takeDamage(3);
    std::cout << player.getName() << " takes 3 damage. Now has " << player.getHealth() << "/" << player.getMaxHealth() << " health." << std::endl;

    for (int i = 0; i < 10;i++){
        std::cout << player.attack() << '\n';
    }

    return 0;
}