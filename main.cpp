#include<raylib.h>

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

    //Game loop.
    while(!WindowShouldClose()){
        //Eventos.

        //Actualziaciones.
        
        //Dibujo.
        BeginDrawing();
        ClearBackground(darkGreen);
        EndDrawing();
    }

    //Cerramos recursos.
    CloseWindow();
    return 0;
}
