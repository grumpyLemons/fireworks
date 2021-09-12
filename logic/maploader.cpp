#include "maploader.h"
#include <ifstream>

std::vector<std::vector<EntityType>> Logic::Utils::mapLoader::LoadMap(const std::string& fileName) {
    std::ifstream = map;
    map.open(fileName);
    char c = map.get();
    while( c > 47 && c < 54 && map.good()) {
        //...
        c = map.get()
    }
}