#include "core/vector.h"
#include <utility>
#include "server.h"
#include "core/vector.h"

namespace Logic {
    class TerrainEntity : public Entity{
    public:
        Core::Vector2 GetPosition();
    private:
        Core::Vector2 coordinates;

    };

}