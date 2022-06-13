//
// Created by lucas on 12/06/22.
//

#include "StateSaver.h"
#include <yaml-cpp/yaml.h>
#include <fstream>

StateSaver::StateSaver() {
}

void StateSaver::saveStatus(std::string name,std::vector<std::vector<int>> map, int players) {
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "name";
    out << YAML::Value << name;
    out << YAML::Key << "players";
    out << YAML::Value << players;
    out << YAML::Key << "map";
    out << YAML::Value << map;
    out << YAML::EndMap;
    std::ofstream fout("../map/"+name+ ".yaml");
    fout << out.c_str();
}
