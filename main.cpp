#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "Colocar torreta");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);


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
                //Obtener coordenadas de la ventana
                sf::Vector2i localPosition = sf::Mouse::getPosition(app);
                int posicionX = localPosition.x;
                int posicionY = localPosition.y;

                //Mostrar las coordenadas
                cout << "Mouse en posicion x: " << posicionX  <<"posicion y: " << posicionY << endl;
            }

        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
