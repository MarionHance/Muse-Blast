// Menu.h
#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    ~Menu();  // Ajoutez la déclaration du destructeur

    void Show(sf::RenderWindow& window);

private:
    sf::RectangleShape playButton;
    sf::Font font;
    sf::Text playText;
    sf::Texture backgroundTexture;

    void HandleEvents(sf::Event& event, sf::RenderWindow& window);
};