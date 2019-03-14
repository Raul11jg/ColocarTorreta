#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>

class Bala
{
    public:
        Bala(sf::Vector2f size);
        void disparar(float speed);
        void setPos(sf::Vector2f newPos);
        int getLeft();
        int getTop();
        int getBottom();
        int getRight();
        void draw(sf::RenderWindow &Window);
        ~Bala();
    private:
        sf::RectangleShape bala;
};

#endif // BALA_H
