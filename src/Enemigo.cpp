#include "Enemigo.h"

Enemigo::Enemigo(sf::Vector2f size)
{
    enemigo.setSize(size);
    sf::Color color(55, 200, 20);
    enemigo.setFillColor(color);
}
void Enemigo::colisionBala(Bala bala){
    if(bala.getRight() > enemigo.getPosition().x &&
    bala.getTop() < enemigo.getPosition().y + enemigo.getSize().y &&
    bala.getBottom() > enemigo.getPosition().y){
        enemigo.setPosition(314214,1213213);
    }
}
void Enemigo::setPos(sf::Vector2f newPos){
    enemigo.setPosition(newPos);
}
void Enemigo::draw(sf::RenderWindow &Window){
    Window.draw(enemigo);
}

Enemigo::~Enemigo()
{
    //dtor
}
