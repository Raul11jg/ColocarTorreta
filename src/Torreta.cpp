#include "Torreta.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Torreta::Torreta(std::string imgDirectory)
{
    if(!torretaTex.loadFromFile(imgDirectory)){
        std::cerr <<"Error al cargar la imagen";
        exit(0);
    }
    torretaSprite.setTexture(torretaTex);
    torretaSprite.setOrigin(sf::Vector2f(256,256));
    torretaSprite.setScale(0.05f,0.05f);
}
int Torreta::getX(){
    return torretaSprite.getPosition().x;
}
int Torreta::getY(){
    return torretaSprite.getPosition().y;
}
void Torreta::draw(sf::RenderWindow &Window){
    Window.draw(torretaSprite);
}
void Torreta::setPos(sf::Vector2f newPos){
    torretaSprite.setPosition(newPos);
}
Torreta::~Torreta()
{
    //dtor

}
