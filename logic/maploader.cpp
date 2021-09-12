#include "maploader.h"
#include <ifstream>

std::vector<std::vector<EntityType>> Logic::Utils::mapLoader::LoadMap(const std::string& fileName) {
    std::ifstream = map;
    map.open(fileName);
    std::string s = map.get();
    std::vector<std::vector<EntityType>> field;
    while(map >> s) {
        std::vector<EntityType> row;
        for(char c : s) {
            if (c > 47 && c < 51) {
                row.push_back(EntityType(c - 48));
            }
        }
        field.push_back(row);
    }
    return field;
}