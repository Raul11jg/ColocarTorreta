#ifndef TORRETA_H
#define TORRETA_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Torreta
{
    public:
        Torreta(sf::Vector2f size){
            torreta.setSize(size);
            sf::Color color(255, 0, 0);

            torreta.setFillColor(color);
        }
        int getX(){
            return torreta.getPosition().x;
        }
        int getY(){
            return torreta.getPosition().y;
        }
        void setPos(sf::Vector2f newPos){
            torreta.setPosition(newPos);
        }
        void setTextura(sf::Texture textura){
            torreta.setTexture(textura);
        }
        void draw(sf::RenderWindow &Window){
            Window.draw(torreta);
        }

    protected:
    private:
        sf::RectangleShape torreta;
};

#endif // TORRETA_H
