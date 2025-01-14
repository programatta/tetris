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

/**
 * Verifica si una celda está fuera de la regilla.
 * 
 * Params:
 *  - row: int
 *  - column: int
 * 
 * Return: true | false
*/
bool Grid::isCellOutside(int row, int column){
    bool isOutside = row<0 || row > this->numRows-1 || column <0 || column > this->numCols-1;
    return isOutside;
}

bool Grid::isCellEmpty(int row, int column){
    return this->grid[row][column] == 0;
}

void Grid::moveRowsDown(){
    int firstRowComplete = 0;
    int completed = 0;
    for(int row=this->numRows-1; row>=0; row--){
        if(this->isRowComplete(row)){
            if(firstRowComplete == 0){
                firstRowComplete = row;
            }
            completed++;
        }
    }

    for(int i=0; i<completed; i++){
        for(int row=firstRowComplete; row>0; row--){
            for(int col=0; col<this->numCols; col++){
                this->grid[row][col] = this->grid[row-1][col];
            }
        }
    }
}


/*===========================================================================*/
/*                           Private Section                                 */
/*===========================================================================*/
bool Grid::isRowComplete(int row){
    bool complete = true;
    for(int i=0; i<this->numCols; i++){
        if(this->grid[row][i] == 0){
            complete = false;
            break;
        }
    }
    return complete;
}
