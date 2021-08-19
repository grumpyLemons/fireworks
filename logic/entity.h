#include "core/vector.h"
#include <utility>
#include "server.h"
#include "core/vector.h"

namespace Logic {
    enum class EntityType {
        Pacman,
        Ghost,
        Orb,
        SolidObject;
    };

    class TerrainEntity {
    public:
        TerrainEntity(EntityType eType);
        EntityType GetType() const;
        const Core::Vector2& GetPosition() const;
    private:
        Core::Vector2 coordinates;
        EntityType type;

    };

}