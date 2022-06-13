//
// Created by lucas on 12/06/22.
//

#ifndef EDITOR_MAPLOADER_H
#define EDITOR_MAPLOADER_H


#include <string>
#include <vector>

class MapLoader {
public:
    MapLoader();
    bool loadMap(std::string& path, std::vector<std::vector<int>>& map,int&,std::string& name);
};


#endif //EDITOR_MAPLOADER_H
