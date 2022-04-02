#include "gameObject.hpp"

#ifndef FOOD_HPP
#define FOOD_HPP

class Food : public GameObject {

    public:
        Food(int x, int y) : GameObject(x, y, 'F') {}
        ~Food() {}
 
};

#endif
