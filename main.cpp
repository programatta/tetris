#include<raylib.h>
#include "grid.hpp"
#include "blocks.cpp"


int main(){
    const int FPS = 60;
    const int screenWidth = 300;
    const int screenHeight = 600;

    //Color {red, green, blue, alpha}
    Color darkGreen = Color{20, 160, 133, 255};

    //Creamos la pantalla.
    InitWindow(screenWidth, screenHeight, "TetrisRaylib");

    //Establecemos el framerate.
    SetTargetFPS(FPS);

    Grid grid = Grid();
    grid.print();

    // LBlock block = LBlock();
    // JBlock block = JBlock();
    // IBlock block = IBlock();
    // OBlock block = OBlock();
    // SBlock block = SBlock();
    // TBlock block = TBlock();
    ZBlock block = ZBlock();

    //Game loop.
    while(!WindowShouldClose()){
        //Eventos.

        //Actualziaciones.
        
        //Dibujo.
        BeginDrawing();
        ClearBackground(darkGreen);
        grid.draw();
        block.draw();
        EndDrawing();
    }

    //Cerramos recursos.
    CloseWindow();
    return 0;
}
