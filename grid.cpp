#include <iostream>
#include "grid.hpp"
#include "colors.hpp"

Grid::Grid(){
    this->numRows = 20;
    this->numCols = 10;
    this->cellSize = 30;

    this->initialize();
    this->colors = getCellColors();
}


/**
 * Inicializa la ventatan lógica a ceros.
*/
void Grid::initialize(){
    for(int row=0; row<this->numRows; row++){
        for(int col=0; col<this->numCols; col++){
            this->grid[row][col] = 0;
        }
    }
}

/**
 * Hace un volcado de la ventana lógica al terminal.
*/
void Grid::print(){
    for(int row=0; row<this->numRows; row++){
        for(int col=0; col<this->numCols; col++){
            std::cout << this->grid[row][col] << " ";   
        }
        std::cout << "\n";
    }
}

/**
 * Dibuja la ventana lógica en la física.
*/
void Grid::draw(){
    for(int row=0; row<this->numRows; row++){
        for(int col=0; col<this->numCols; col++){
            int colorId = this->grid[row][col];
            Color color = this->colors.at(colorId);
            int posX = col * this->cellSize;
            int posY = row * this->cellSize;
            DrawRectangle(posX+1, posY+1, this->cellSize-1, this->cellSize-1, color);
        }
    }
}

/*===========================================================================*/
/*                           Private Section                                 */
/*===========================================================================*/
