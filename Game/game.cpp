// Game.cpp
#include "Game.h"

Game::Game() {
    Engine::GetInstance()->Init();

    window.create(sf::VideoMode(1920, 1080), "Music Blast");
    sceneModule = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
    sceneModule->SetScene<DefaultScene>();
}

void Game::Run() {
    mainMenu.Show(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // G�rez d'autres �v�nements si n�cessaire
        }

        // Mettez � jour et dessinez le contenu du jeu ici

        window.clear();
        // Dessinez le contenu du jeu
        window.display();
    }
}