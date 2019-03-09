
#ifndef ENEMIGO_H
#define ENEMIGO_H


class Enemigo
{
    public:
        Enemigo(sf::Vector2f size){
            enemigo.setSize(size);
            sf::Color color(55, 200, 20);
            enemigo.setFillColor(color);
        }
        void colisionBala(Bala bala){
            if(bala.getRight() > enemigo.getPosition().x &&
            bala.getTop() < enemigo.getPosition().y + enemigo.getSize().y &&
            bala.getBottom() > enemigo.getPosition().y){
                enemigo.setPosition(314214,1213213);
            }
        }
        void setPos(sf::Vector2f newPos){
            enemigo.setPosition(newPos);
        }
        void draw(sf::RenderWindow &Window){
            Window.draw(enemigo);
        }
    protected:
    private:
    sf::RectangleShape enemigo;
};

#endif // ENEMIGO_H


