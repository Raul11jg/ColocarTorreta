#include "Enemigo.h"
using namespace std;

Enemigo::Enemigo(sf::Vector2f size)
{
    enemigo.setSize(size);
    sf::Color color(55, 200, 20);
    enemigo.setFillColor(color);
}/*
void Enemigo::colisionBala(Bala bala){

    if(bala.getRight() > enemigo.getPosition().x &&
        bala.getTop() < enemigo.getPosition().y + enemigo.getSize().y &&
        bala.getBottom() > enemigo.getPosition().y && bala.getLeft() < enemigo.getPosition().x +
        enemigo.getSize().x){
        enemigo.setPosition(314214,1213213);
        cout << "Enemigo destruido \n";
    }
}*/
void Enemigo::setPos(sf::Vector2f newPos){
    enemigo.setPosition(newPos);
}
int Enemigo::getPosX(){return enemigo.getPosition().x;}
int Enemigo::getPosY(){return enemigo.getPosition().y;}
void Enemigo::draw(sf::RenderWindow &Window){
    Window.draw(enemigo);
}

Enemigo::~Enemigo()
{
    //dtor
}
