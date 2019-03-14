#include "Bala.h"

Bala::Bala(sf::Vector2f size)
{
    bala.setSize(size);
    sf::Color color(255, 255, 0);
    bala.setFillColor(color);
}

void Bala::disparar(float speed){
    bala.move(speed, 0);
}
void Bala::setPos(sf::Vector2f newPos){
    bala.setPosition(newPos);
}
int Bala::getLeft(){
    return bala.getPosition().x;
}
int Bala::getTop(){
    return bala.getPosition().y;
}
int Bala::getBottom(){
    return bala.getPosition().y + bala.getSize().y;
}
int Bala::getRight(){
    return bala.getPosition().x + bala.getSize().x;
}
void Bala::draw(sf::RenderWindow &Window){
    Window.draw(bala);
}
Bala::~Bala()
{
    //dtor
}
