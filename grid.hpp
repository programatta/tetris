#pragma once

#include<vector>
#include<raylib.h>

class Grid {
    public:
        Grid();
        int grid[20][10];
        void initialize();
        void print();
        void draw();

    private:
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};
