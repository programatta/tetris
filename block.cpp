#include "block.hpp"
#include <raylib.h>

Block::Block(){
    this->cellSize = 30;
    this->rotationState = 0;
    this->colors = getCellColors();
}

/**
 * Dibuja el bloque en la pantalla.
*/
void Block::draw(){
    std::vector<Position> tiles = this->cells[this->rotationState];

    for(Position tile:tiles){
        int posX = tile.column * this->cellSize;
        int posY = tile.row * this->cellSize;
        Color color = this->colors[this->id];
        DrawRectangle(posX+1, posY+1, this->cellSize-1, this->cellSize-1, color);
    }
}