#include "Bala.h"
#include <SFML/Graphics.hpp>

Bala::Bala(sf::Vector2f size)
{
    bala.setSize(size);
    sf::Color color(255, 255, 0);
    bala.setFillColor(color);
}

void Bala::disparar(float speed){
    bala.move(0,-speed);
}
void Bala::setPos(sf::Vector2f newPos){
    bala.setPosition(newPos);
}
int Bala::getLeft(){
    return bala.getPosition().x+ bala.getSize().y;
}
int Bala::getTop(){
    return bala.getPosition().y+ bala.getSize().x;
}
int Bala::getBottom(){
    return bala.getPosition().y + bala.getSize().y;
}
int Bala::getRight(){
    return bala.getPosition().x + bala.getSize().x;
}
void Bala::perseguir(Enemigo enemigo){
    sf::Vector2 direction = (enemigo.getPosX() - bala.getPosition().x, enemigo.getPosY() - bala.getPosition().y);
    bala.move(3 * direction);
}
void Bala::draw(sf::RenderWindow &Window){
    Window.draw(bala);
}
Bala::~Bala()
{
    bala.setSize(sf::Vector2f(0, 0));
}
