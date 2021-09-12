#include "server.h"
#include <vector>
#include "core/vector.h"
#include "entity.h"

namespace Logic {
    class Cell {
    public:
        Cell() = default;
        TerrainEntity* GetTerrainEntity() {return entity;}
        TerrainEntity* GetEntity();
        TerrainEntity SwapEntity(TerrainEntity* newValue);
    private:
        TerrainEntity* entity = nullptr;
    };

    class Field {
    public:
        Field(std::size_t x, std::size_t y);
        Cell& GetCell(Core::Vector2 coordinates);
        TerrainEntity* GetEntity(Point position);
        TerrainEntity* ConsumeEntity(Point position);

    private:
        std::vector<std::vector<Cell>> board;

    };
}