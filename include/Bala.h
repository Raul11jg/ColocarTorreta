#ifndef BALA_H
#define BALA_H
#include "Enemigo.h"
#include <iostream>
#include <SFML/Graphics.hpp>
class Enemigo;
class Bala
{
    public:
        Bala(sf::Vector2f size);
        void disparar(float speed);
        void perseguir(int enemigoPosX,int enemigoPosY );
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
