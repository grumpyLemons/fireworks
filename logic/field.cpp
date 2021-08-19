#include "field.h"

namespace Logic
{
    Field::Field(std::size_t x, std::size_t y) {
        std::vector<Cell> temp_vector(y);
        for (int i = 0; i < y; i++)
        {
            board.push_back(temp_vector);
        }
    }
    Cell& Field::GetCell(Core::Vector2 coordinates) {
        return board[coordinates.X][coordinates.Y];
    }
}