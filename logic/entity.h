#include "core/vector.h"
#include <utility>
#include "server.h"
#include "core/vector.h"
#include "core/point.h"

namespace Logic {
    enum class EntityType {
        Orb, //char 0 = 48
        AlphaOrb,
        SolidObject,
        Empty,
        Pacman,
        Ghost,
    };

    class TerrainEntity {
    public:
        TerrainEntity(EntityType eType);
        EntityType GetType() const;
        const Core::Vector2& GetPosition() const;
        Point UpdatePosition(Point position);
    private:
        Core::Vector2 coordinates;
        EntityType type;

    };

}