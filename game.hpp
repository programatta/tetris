#pragma once

#include "grid.hpp"
#include "block.hpp"


class Game {
    public:
        Game();
        Grid grid;

        Block getRandomBlock();
        std::vector<Block> getAllBlocks();
        void handleInput();
        void update();
        void draw();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        int nextX, nextY;
        double lastUpdate;
        double sleepFallTime;
        bool isUserInput;
        void moveBlockLeft();
        void moveBlockRight();
        void moveBlockDown();
        void moveBlockFastDown();
        void rotateBlock();
        bool isBlockOutside();
        void lockBlock();
        bool isBlockCollide();
};
