#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

const float vida_bala_s = 4.0f;     //Vida bala
const float velocidad = 1.f;        //Velocidad pixel/segundo
const float disparo_segundo = 0.5f; //Frecuencia/ segundo

class Bala
{
    public:
        Bala(sf::Vector2f size){
            bala.setSize(size);
            sf::Color color(255, 255, 0);
            bala.setFillColor(color);
        }
        void disparar(float speed){
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
        sf::Vector2f m_direccion_movimiento;
        float remaining;
        bool alive;
    private:
        sf::RectangleShape bala;
};

#endif // BALA_H
