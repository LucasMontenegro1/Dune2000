//
// Created by lucas on 10/06/22.
//

#include "Editor.h"

Editor::Editor(sf::Vector2i resolution): window(sf::VideoMode(resolution.x, resolution.y),
                                                "Dune - Editor", sf::Style::Close | sf::Style::Resize),
                                                game_over(false), menu(0,0,700,1000),level(1000, std::vector<int>(1000)){
    this->posX = 0;
    this->posY = 0;
    this->view.setViewport(sf::FloatRect(0.f, 0.f, 0.75f, 1.0f));
    this->menu_view.setViewport(sf::FloatRect(0.81f, 0.f, 0.25f, 0.70f));
    this->ground = new Ground(level, 1000, 1000);
    this->camera = new Camera(view, posX, posY, resolution.x, resolution. y);

}



void Editor::gameloop() {
    bool dragMode = false;
    while (!game_over) {
        window.clear();
        window.setView(view);
        camera->render(window);
        updateCamera();
        window.setView(menu_view);
        menu.render(window);
        window.display();

        while (window.isOpen()) {

            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (sf::Keyboard::LControl) {
                        dragMode = true;
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    if (sf::Keyboard::LControl) {
                        dragMode = false;
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed || dragMode) {
                    window.setView(view);
                    sf::Vector2i WinPos = sf::Mouse::getPosition(window);
                    sf::Vector2f pos = view.getSize();
                    int x = window.getSize().x;
                    float scale = view.getViewport().width;
                    if (WinPos.x < x * scale) {
                        camera->render(window);
                        sf::Vector2f mouse = window.mapPixelToCoords(WinPos);
                        ground->setsSprite(mouse.y / 16, mouse.x / 16, 2);
                    }
                }
                menu.update(window, event);
            }

            Vector2i posicion = Mouse::getPosition(window);

            window.clear();
            window.setView(view);
            camera->render(window);
            camera->update(posicion, *ground);
            updateCamera();
            window.setView(menu_view);
            menu.render(window);
            window.display();
            if (!window.isOpen()) {
                game_over = true;
            }
        }
    }

}

void Editor::updateCamera() {
    posX = camera->get_posX();
    posY = camera->get_posY();
    int limitX = posX +  window.getSize().x;
    int limitY = posY + window.getSize().y;
    for(int i = posX; i < limitX; i+=16){
        for(int j = posY; j < limitY; j +=16){
            int col = i / 16;
            int row = j / 16;
            if(ground->identify_texture(col, row)){
                ground->set(i,j);
                window.draw(*ground);
            }
        }
    }
}

