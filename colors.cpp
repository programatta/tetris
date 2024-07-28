#include "colors.hpp"

const Color darkGray = {26, 31, 40, 255}; //Color de fondo
const Color green = {47, 210, 32, 255};   //Pieza 1
const Color red = {232, 18, 18, 255};     //Pieza 2
const Color orange = {226, 116, 17, 255}; //Pieza 3
const Color yellow = {237, 234, 6, 255};  //Pieza 4
const Color purple = {166, 0, 247, 255};  //Pieza 5
const Color cyan = {21, 204, 209, 255};   //Pieza 6
const Color blue = {13, 64, 216, 255};    //Pieza 7

/**
 * Devuelve la lista de colores que se van a usar en las celdas para pintar los
 * bloques.
 * 
 * return std::vector<Color>
*/
std::vector<Color> getCellColors(){
    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}