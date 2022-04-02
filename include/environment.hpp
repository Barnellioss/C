#include <iostream>
#include <chrono>
#include <thread>
#include "dog.hpp"
#include "food.hpp"
#include "cat.hpp"

#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

class Environment {

    private:
        Dog dog1;
        Dog dog2;
        Food* food1;
        Cat cat1("Vasia", 0, 0, 100);
        Cat cat2("Leopold", 0, 0, 100);
        int width;
        int height;

        void generateFood() {
            this->food1 = new Food(std::rand() % this->width, std::rand() % this->height);
        }

        void rowSeparator() {
            for (int x = 0; x <= this->width * 2; x++)
                    std::cout << "-";
                std::cout << std::endl;
        }

        void vypisHernehoSveta() {
            std::cout << "Herny svet:" << std::endl;

            for (int y = 0; y < this->height; y++)
            {
                this->rowSeparator();

                for (int x = 0; x < this->width; x++)
                {
                    std::cout << "|";

                    if (x == this->dog1.getX() && y == this->dog1.getY())
                    {
                        std::cout << this->dog1.getSymbol();
                    }
                    else if (x == dog2.getX() && y == dog2.getY())
                    {
                        std::cout << this->dog2.getSymbol();
                    }

                    else if (x == this->cat1.getX() && y == this->cat1.getY())
                    {
                        std::cout << this->cat1.getSymbol();
                    }
                    else if (x == cat2.getX() && y == cat2.getY())
                    {
                        std::cout << this->cat2.getSymbol();
                    }

                    else if (x == food1->getX() && y == food1->getY())
                    {
                        std::cout << this->food1->getSymbol();
                    }
                    else
                    {
                        std::cout << " ";
                    }
                }

                std::cout << "|" << std::endl;
            }

            this->rowSeparator();

            std::cout << "Energia psa 1: " << this->dog1.getEnergy() << std::endl;
            std::cout << "Energia psa 2: " << this->dog2.getEnergy() << std::endl << std::endl;

            std::cout << "Energia kocura 1: " << this->cat1->getEnergy() << std::endl;
            std::cout << "Energia psa 2: " << this->cat2.getEnergy << std::endl << std::endl;

            std::cout <<  cat1.timeForEscape << std::endl;
            std::cout <<  cat2.timeForEscape << std::endl;
        }

    public:
        Environment(int width, int height) : width(width), height(height), dog1(0, 0, 10), dog2(dog1) {
            generateFood();
        }
        ~Environment() {}

        void run() {
            while (this->dog1.getEnergy() > 0 || this->dog2.getEnergy() > 0) {
                if (this->dog1.getEnergy() > 0) {
                    this->dog1.move(std::rand() % this->width, std::rand() % this->height);
                    if (this->dog1.eat(this->food1)) {
                        generateFood();
                    }
                }

                if (this->dog2.getEnergy() > 0) {
                    this->dog2.move(std::rand() % this->width, std::rand() % this->height);
                    if (this->dog2.eat(this->food1)) {
                        generateFood();
                    }
                }

                this->vypisHernehoSveta();
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            }
        }
};

#endif