//
// Created by lucas on 13/06/22.
//

#ifndef EDITOR_CONSTRUCTIONCENTER_H
#define EDITOR_CONSTRUCTIONCENTER_H


#include <SFML/Graphics/Sprite.hpp>

class ConstructionCenter {
    int x;
    int y;
    sf::Sprite shape;
public:
    ConstructionCenter(int x, int y);
    void render(sf::RenderTarget& target);

};


#endif //EDITOR_CONSTRUCTIONCENTER_H
