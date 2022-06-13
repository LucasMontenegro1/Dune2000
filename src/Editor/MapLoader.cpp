//
// Created by lucas on 12/06/22.
//

#include <yaml-cpp/yaml.h>
#include <iostream>

#include "MapLoader.h"
MapLoader::MapLoader() {

}


bool MapLoader::loadMap(std::string& path, std::vector<std::vector<int>>& map, int& players, std::string& name) {
    YAML::Node config = YAML::LoadFile(path);
    map = config["map"].as<std::vector<std::vector<int>>>();
    players = config["players"].as<int>();
    name = config["name"].as<std::string>();
    return true;
}