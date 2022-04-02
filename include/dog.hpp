#include "gameObject.hpp"
#include "food.hpp"

class Dog : public GameObject {
    private:
        int energy;

    public:
        Dog(int x, int y, int energy) : GameObject(x, y, 'D'), energy(energy) {}
        ~Dog() {}

        Dog(const Dog& other) : GameObject(other.x, other.y, other.symbol), energy(other.energy) {
            std::cout << "Dog is copied !!!" << std::endl;
        }

        int getEnergy() { return this->energy; }

        void move(int x, int y) {
            this->x = x;
            this->y = y;
            this->energy -= 1;
        }

        bool eat(Food *food) {
            if (food->getX() == this->x && food->getY() == this->y) {
                delete food;
                this->energy += 10;

                return true;
            }
            else
            {
                return false;
            }
        }
};


