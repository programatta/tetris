#include "grid.hpp"
#include <iostream>


Grid::Grid(){
    this->numRows = 20;
    this->numCols = 10;
    this->cellSize = 30;

    this->initialize();
    this->colors = this->getCellColors();
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

/**
 * Devuelve la lista de colores que se van a usar en las celdas para pintar los
 * bloques.
 * 
 * return std::vector<Color>
*/
std::vector<Color> Grid::getCellColors(){
    Color darkGray = {26, 31, 40, 255}; //Color de fondo
    Color green = {47, 210, 32, 255};   //Pieza 1
    Color red = {232, 18, 18, 255};     //Pieza 2
    Color orange = {226, 116, 17, 255}; //Pieza 3
    Color yellow = {237, 234, 6, 255};  //Pieza 4
    Color purple = {166, 0, 247, 255};  //Pieza 5
    Color cyan = {21, 204, 209, 255};   //Pieza 6
    Color blue = {13, 64, 216, 255};    //Pieza 7

    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}
