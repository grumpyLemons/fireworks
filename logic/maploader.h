#include "server.h"
#include "entity.h"
#include <string>
#include <vector>


namespace Logic::Utils {

    class mapLoader {
    public:
        std::vector<std::vector<EntityType>> LoadMap(const std::string& fileName);
    };

}