#include "block.hpp"
#include <raylib.h>

Block::Block(){
    this->cellSize = 30;
    this->rotationState = 0;
    this->colors = getCellColors();
    this->columnOffset = 0;
    this->rowOffset = 0;
}

/**
 * Dibuja el bloque en la pantalla.
*/
void Block::draw(){
    std::vector<Position> tiles = this->getCellPositions(); //this->cells[this->rotationState];

    for(Position tile:tiles){
        int posX = tile.column * this->cellSize;
        int posY = tile.row * this->cellSize;
        Color color = this->colors[this->id];
        DrawRectangle(posX+1, posY+1, this->cellSize-1, this->cellSize-1, color);
    }
}

/**
 * Mueve el bloque
*/
void Block::move(int rows, int columns){
    this->rowOffset += rows;
    this->columnOffset += columns;
}

std::vector<Position> Block::getCellPositions(){
    std::vector<Position> tiles = this->cells[this->rotationState];
    std::vector<Position> movedTitles;

    for(Position item:tiles){
        int posX = item.row + this->rowOffset;
        int posY = item.column + this->columnOffset;
        Position newPos = Position(posX, posY);
        movedTitles.push_back(newPos);
    }

    return movedTitles;
}

void Block::rotate(){
  this->rotationState = (this->rotationState + 1) % 4;  
}

void Block::undoRotate(){
    this->rotationState = this->rotationState == 0 ? this->cells.size()-1 : this->rotationState-1;
}