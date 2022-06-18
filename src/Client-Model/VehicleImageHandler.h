//
// Created by lucas on 31/05/22.
//

#ifndef VEHICLEIMAGEHANDLER_H
#define VEHICLEIMAGEHANDLER_H

#include "Button.h"

class VehicleImageHandler {
    std::string house;
    Button trike;
    Button sonicTank;
    Button raider;
    Button deviator;
    Button devastator;
    Button tank;
    Button harvester;
    void HandleVehiclesActions(sf::Event &event, sf::RenderWindow& window);
    void setVehiclesTextures();
public:
    void displayVehicles(sf::RenderWindow& window);
    void setVehicleMenu();
    void updateVehicles(sf::Event &event, sf::RenderWindow& target);
    explicit VehicleImageHandler(std::string house);
};


#endif
