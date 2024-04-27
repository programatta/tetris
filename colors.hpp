#pragma once

#include <raylib.h>
#include <vector>


//Usamos extern para poder compartir con otras ficheros.
extern const Color darkGray;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;

std::vector<Color> getCellColors();
