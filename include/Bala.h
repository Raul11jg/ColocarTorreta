#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Bala
{
    public:
        Bala(sf::Vector2f size){
            bala.setSize(size);
        }
        void disparar(int speed){
            bala.move(speed, 0);
        }
        void draw(sf::RenderWindow &app){
            app.draw(bala);
        }
        void setPos(sf::Vector2f newPos){
            bala.setPosition(newPos);
        }
    protected:
    private:
        sf::RectangleShape bala;
};

#endif // BALA_H
