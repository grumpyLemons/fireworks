#include "server.h"
#include <vector>
#include "core/vector.h"
#include "entity.h"

namespace Logic {
    class Cell {
    public:
        Cell() = default;
        TerrainEntity* GetTerrainEntity() {return entity;}
    private:
        TerrainEntity* entity = nullptr;
    };

    class Field {
    public:
        Field(std::size_t x, std::size_t y);
        Cell& GetCell(long x, long y);
    private:
        std::vector<std::vector<Cell>> board;

    };
}