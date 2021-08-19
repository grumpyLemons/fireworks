#include "entity.h"

namespace Logic {
    class Pacman : public TerrainEntity, public Entity {
    };

    class Ghost : public TerrainEntity, public Entity {
    };

    class SolidObject : public TerrainEntity {
    };

    class Orb : public TerrainEntity {
    };

    class AlphaOrb : public TerrainEntity {
    };
}