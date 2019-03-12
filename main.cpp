#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bala.h"
#include "Torreta.h"
#include "Enemigo.h"
#include <vector>

using namespace std;

int main()
{

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "Colocar torreta");


    //definir rectangulo, para selector
    sf::RectangleShape selector(sf::Vector2f(30.f, 30.f));
    sf::Color trasnparente(0, 0, 0, 1); //Cuadrado transparente
    selector.setFillColor(trasnparente);

    //Pintar borde del rectangulo, que sera e selector
    selector.setOutlineThickness(4.f);
    selector.setOutlineColor(sf::Color(255, 255, 255)); //Color blanco
    bool ponerTorreta=false;

    //Defino vector donde meto todas las balas
    std::vector<Bala> vectorBalas;

    //Defino vector donde iran las torretas
    std::vector<Torreta> vectorTorreta;


    bool disparando = false;

    //Crear enemigo en una posicion fija
    Enemigo enemigo(sf::Vector2f(40.f,40.f));
    enemigo.setPos(sf::Vector2f(150.f,150.f));


    //Crear matriz para colocar las torretas
    class TileMap : public sf::Drawable, public sf::Transformable

{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // get the current tile number
                int tileNumber = tiles[i + j * width];

                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

    // define the level with an array of tile indices
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
     TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();


            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                ponerTorreta=true;
            }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                disparando=true;
             }


         if(ponerTorreta ==true){
            //Obtener coordenadas de la ventana
            sf::Vector2i localPosition = sf::Mouse::getPosition(app);
            int posicionX = localPosition.x;
            int posicionY = localPosition.y;

            //Obtener parte entera de la division
            int i = (posicionX/32);
            int j = (posicionY/32);

            //Crea la clase torreta dandole un tamanio
            Torreta* torreta = new Torreta("ballesta.png");
            //Coloca la torreta en una posicion llamando a una funcion que hemos creado en la clase torreta setPos
            torreta->setPos(sf::Vector2f(i*32.f ,j*32.f));
            //Anade la torreta creada al vector de torretas
            vectorTorreta.push_back(*torreta);
            ponerTorreta = false;
         }

            //Dibujar selector en el mapa para poner la torreta donde marque

                //Obtener coordenadas de la ventana
                sf::Vector2i localPosition = sf::Mouse::getPosition(app);
                int posicionX = localPosition.x;
                int posicionY = localPosition.y;

                //Obtener parte entera de la division
                int i = (posicionX/32);
                int j = (posicionY/32);

                //Mostrar las coordenadas
                cout << "Mouse en posicion x: " << posicionX  <<"posicion y: " << posicionY << endl;
                //Mostrar las i  j
                cout << "i: " << i  <<"j: " << j << endl;

                //Dibujar el selector en el cuadrado de la matriz
                selector.setPosition(i*32.f ,j*32.f);
        }



        // Clear screen
        app.clear();
        //Dibujar mapa
        app.draw(map);
        //Dibujar enemigo
        enemigo.draw(app);
         if(disparando ==true){
                //Recorro el vector de torretas, las cuales dispararan al centro del mapa cada x tiempo
                for(int i=0; i<vectorTorreta.size(); i++){
                    Bala nuevaBala(sf::Vector2f(5.f,5.f));
                    nuevaBala.setPos(sf::Vector2f(vectorTorreta[i].getX(), vectorTorreta[i].getY()));
                    vectorBalas.push_back(nuevaBala);
                }
                disparando=false;
         }

         for(int i=0; i<vectorBalas.size(); i++){
            vectorBalas[i].draw(app);
            vectorBalas[i].disparar(3);
            //Si la bala colisiona con el enemigo, muere
            enemigo.colisionBala(vectorBalas[i]);
         }

        //Recorrer el vector de torretas y dibujar las torretas
        for(int i=0; i<vectorTorreta.size(); i++)
            vectorTorreta[i].draw(app);

        //Dibujar la torreta

        app.draw(selector);

        // Update the window
        app.display();


    }

    return EXIT_SUCCESS;
}
