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
            sf::Color color(255, 255, 0);
            bala.setFillColor(color);
        }
        void disparar(int speed){
            bala.move(speed, 0);
        }
        void setPos(sf::Vector2f newPos){
            bala.setPosition(newPos);
        }
        int getLeft(){
            return bala.getPosition().x;
        }
        int getTop(){
            return bala.getPosition().y;
        }
        int getBottom(){
            return bala.getPosition().y + bala.getSize().y;
        }
        int getRight(){
            return bala.getPosition().x + bala.getSize().x;
        }
        void draw(sf::RenderWindow &Window){
            Window.draw(bala);
        }
    protected:
    private:
        sf::RectangleShape bala;
};

#endif // BALA_H
