#include "Bala.h"
#include <SFML/Graphics.hpp>
#include <math.h>

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
void Bala::perseguir(int enemigoPosX,int enemigoPosY ){
    sf::Clock clock;
    float delta = clock.restart().asSeconds();
    float angle = atan2(enemigoPosY - bala.getPosition().y, enemigoPosX - bala.getPosition().x);
    angle =angle * 180 / (atan(1) * 4);
    sf::Vector2f newpos((cos(angle))*2, (sin(angle))*2);

    //sf::Vector2u direction = normalize(enemigoPosY - bala.getPosition().y, enemigoPosX - bala.getPosition().x);
    double direction = sqrt(pow(enemigoPosY - bala.getPosition().y, 2) + pow(enemigoPosX - bala.getPosition().x, 2));
    bala.move(newpos);
}
void Bala::draw(sf::RenderWindow &Window){
    Window.draw(bala);
}
Bala::~Bala()
{
    bala.setSize(sf::Vector2f(0, 0));
}
