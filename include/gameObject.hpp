
#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

class GameObject {
    protected:
        int x, y;
        char symbol;
    public:
        GameObject(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {}
        ~GameObject() {}

        int getX() { return this->x; }
        int getY() { return this->y; }
        char getSymbol() { return this->symbol; }
};

#endif