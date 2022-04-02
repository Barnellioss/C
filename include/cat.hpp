//
// Created by Admin on 02.04.2022.
//
#include <string>
#include <iostream>
#include <cmath>
#include "gameObject.hpp"
#ifndef CPP7_CAT_HPP
#define CPP7_CAT_HPP
typedef std::string string;
typedef int number;

class Dog;

class Cat :: public GameObject{
    private:
        string name;
        string calmSound;
        string angrySound;
        double energy
    public:
    Cat();
    Cat(string name, number x, number y, char symbol, double energy): GameObject(x,y, symbol), name(name), energy(energy){};
    ~Cat(){};
    string getName(){
        return this->name;
    }
    string getCalmSound(){
        return this->calmSound;
    }
    string getAngrySound(){
        return this->angrySound;
    }

    void move(number x, number y){
        if(x == this->x && y == this->y){
            std::cout << "You're here" << std::endl;
        }
        else{
            energy -= pow(pow(this->x - x, 2) + pow(this->y - y, 2), 0,5);
            this->x = x;
            this->y = y;
        }
    }

    bool eat(Food *food) {
        if (food->getX() == this->x && food->getY() == this->y) {
            delete food;
            this->energy += 20;
            std::cout << "Food is so delicious, " << this->calmSound << std::endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void timeForEscape(Dog* dog){
        if(dog->getX() == this->getX() && dog->getY() == this->getY()){
            std::cout << "Ohhhh now, this dog is here, it's time for run, " << this->angrySound <<std::endl;
            this->energy--;
            this->y--;
            std::cout << "Energy has been decremented, we are here" << this->x << " " << this->y << std::endl;
        }
        else{
            std::cout << "Everything is OK, it's not time to fear" << std::endl;
        }
    }
};

#endif //CPP7_CAT_HPP
