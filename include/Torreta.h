#ifndef TORRETA_H
#define TORRETA_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Torreta
{
    public:
        Torreta(std::string imgDirectory){

        if (!tex.loadFromFile(imgDirectory))
        {
            std::cerr << "Error cargando la imagen ballesta.png";
            exit(0);
        }
        sprite.setTexture(tex);
        //Coloco el origen del sprite en la mitad de la imagen, que tiene 150ancho 120alto. inicialmente el origen se pone en 0,0, top left.
        sprite.setOrigin(sf::Vector2f(256, 256));

        }
        int getX(){
            return sprite.getPosition().x;
        }
        int getY(){
            return sprite.getPosition().y;
        }
        void setPos(sf::Vector2f newPos){
            sprite.setPosition(newPos);
        }
        void draw(sf::RenderWindow &Window){
            Window.draw(sprite);
        }

    protected:
    private:
        sf::Texture tex;
        sf::Sprite sprite;

};

#endif // TORRETA_H
