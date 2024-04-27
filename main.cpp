#include<raylib.h>
#include "grid.hpp"


int main(){
    const int FPS = 60;
    const int screenWidth = 300;
    const int screenHeight = 600;

    //Color {red, green, blue, alpha}
    Color darkGreen = Color{20, 160, 133, 255};
    //Color darkGray = {26, 31, 40, 255};

    //Creamos la pantalla.
    InitWindow(screenWidth, screenHeight, "TetrisRaylib");

    //Establecemos el framerate.
    SetTargetFPS(FPS);

    Grid grid = Grid();
    grid.print();

    //Game loop.
    while(!WindowShouldClose()){
        //Eventos.

        //Actualziaciones.
        
        //Dibujo.
        BeginDrawing();
        ClearBackground(darkGreen);
        grid.draw();
        EndDrawing();
    }

    //Cerramos recursos.
    CloseWindow();
    return 0;
}
