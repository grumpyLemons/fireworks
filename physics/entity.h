#include "core/vector.h"
#include <utility>
#include "server.h"

namespace Logic {
    class TerrainEntity : public Entity{
    public:
        std::pair<long, long> GetPosition();
    private:
        std::pair<long, long> coordinates;

    };

}