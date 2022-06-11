//
// Created by lucas on 10/06/22.
//

#include "Editor.h"

Editor::Editor(): window(sf::VideoMode(1366, 768), "Dune - Editor", sf::Style::Close | sf::Style::Resize),
game_over(false) {

}

void Editor::gameloop() {
    while (!game_over) {
        window.clear();
        window.display();

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }
        }
        if (!window.isOpen()){
            game_over = true;
        }
    }

}