#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SFML/Graphics.hpp>
#include <Bala.h>
class Enemigo
{
    public:
        Enemigo(sf::Vector2f size);
        void colisionBala(Bala bala);
        void setPos(sf::Vector2f newPos);
        void draw(sf::RenderWindow &Window);
        ~Enemigo();
    private:
    sf::RectangleShape enemigo;
};

#endif // ENEMIGO_H
