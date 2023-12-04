// Menu.cpp
#include "Menu.h"

Menu::Menu() {
    playButton.setSize(sf::Vector2f(200.0f, 50.0f));
    playButton.setFillColor(sf::Color::Red);

    if (!backgroundTexture.loadFromFile("Assets/menu_fond.jpg")) {
        // Gestion des erreurs si l'image ne peut pas �tre charg�e
    }

    if (!font.loadFromFile("Musicals.ttf")) {
        // Gestion des erreurs si la police ne peut pas �tre charg�e
    }

    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(24);
    playText.setFillColor(sf::Color::White);

    // Centrez horizontalement et verticalement le texte dans le bouton
    sf::FloatRect textBounds = playText.getLocalBounds();
    playText.setPosition(
        playButton.getPosition().x + (playButton.getSize().x - textBounds.width) / 2.0f,
        playButton.getPosition().y + (playButton.getSize().y - textBounds.height) / 2.0f
    );
}

Menu::~Menu() {
    // Lib�rez les ressources si n�cessaire
}


void Menu::Show(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            HandleEvents(event, window);
        }

        window.clear();

        // Dessinez le fond d'�cran
        sf::RectangleShape backgroundShape;
        backgroundShape.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
        backgroundShape.setTexture(&backgroundTexture);
        window.draw(backgroundShape);

        // Dessinez les �l�ments du menu
        window.draw(playButton);
        window.draw(playText);

        window.display();
    }
}

void Menu::HandleEvents(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        // V�rifiez si le clic de la souris est sur le bouton "Play"
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f mousePositionF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

        if (playButton.getGlobalBounds().contains(mousePositionF)) {
            // Le bouton "Play" a �t� cliqu�, lancez le jeu
            window.clear();
            window.display();
            // Ne fermez pas la fen�tre ici, laissez la boucle principale g�rer la fermeture
        }
    }
}