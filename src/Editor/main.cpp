#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "textBox.h"
#include "camera.h"
#include "EditorMenu.h"
#include "Editor.h"
#include "Map.h"

using namespace sf;

int posX;
int posY;
void update(Camera& camera, Ground& ground, RenderWindow& window){
    posX = camera.get_posX();
    posY = camera.get_posY();
    int limitX = posX +  1366;
    int limitY = posY + 768;
    for(int i = posX; i < limitX; i+=16){
        for(int j = posY; j < limitY; j +=16){
            int col = i / 16;
            int row = j / 16;
            if(ground.identify_texture(col, row)){
                ground.set(i,j);
                window.draw(ground);
            }
        }
    }
}

int main() {
    int sizeX = 1366;//Esto en un futuro es
    int sizeY = 768;//Algo que se pasa por parametro
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Dune", sf::Style::Close | sf::Style::Resize);

    posX = 0;
    posY = 0;

    View view;
   View menu_view;
    view.setViewport(sf::FloatRect(0.f, 0.f, 0.75f, 1.0f));
   menu_view.setViewport(sf::FloatRect(0.81f, 0.f, 0.25f, 0.70f));
   EditorMenu editor_menu(0,0,700,1000);

   Camera camera(view, posX, posY, sizeX, sizeY);
    std::vector<std::vector<int>> level(1000, std::vector<int>(1000));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <10 ; ++j) {
            level[i][j] = 1;
        }

    }
    Ground ground(level, 1000, 1000);

    window.setView(menu_view);
    window.clear();
    editor_menu.render(window);
    camera.render(window);
    update(camera, ground, window);
    window.display();

    while(window.isOpen()){
        Vector2i posicion = Mouse::getPosition(window);
        camera.update(posicion, ground);
        Event event;
        window.setView(view);
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
            if (event.type == Event::MouseButtonReleased){

                window.setView(menu_view);
                sf::Vector2i WinPos = sf::Mouse::getPosition(window);
                sf::Vector2f pos = view.getSize();
                if (WinPos.x < 1366*0.75) {
                    camera.render(window);
                    sf::Vector2f mouse = window.mapPixelToCoords(WinPos);
                    ground.setsSprite(mouse.y / 16, mouse.x / 16);
                }
            }


        }

        window.clear();
        window.setView(view);
        camera.render(window);
        update(camera, ground, window);
        window.setView(menu_view);
        editor_menu.render(window);
        window.display();
    }


}