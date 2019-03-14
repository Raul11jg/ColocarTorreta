#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Bala.h"
#include <SFML/Graphics.hpp>


class Enemigo
{
    public:
        Enemigo(sf::Vector2f size);
        //void colisionBala(Bala bala);
        void setPos(sf::Vector2f newPos);
        int getPosX();
        int getPosY();
        void draw(sf::RenderWindow &Window);
        ~Enemigo();
    private:
    sf::RectangleShape enemigo;
};

#endif // ENEMIGO_H
