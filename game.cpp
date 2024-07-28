#include "game.hpp"
#include <random>
#include <iostream>
#include "blocks.cpp"


Game::Game(){
    this->grid = Grid();
    this->blocks = this->getAllBlocks();
    this->currentBlock = this->getRandomBlock();
    this->nextBlock = this->getRandomBlock();
    this->lastUpdate = 0;
    this->sleepFallTime = 0.200;
}

Block Game::getRandomBlock(){
    if(this->blocks.empty()){
        this->blocks = this->getAllBlocks();
    }
    int randomIndex = rand() % this->blocks.size();
    Block block = this->blocks[randomIndex];
    this->blocks.erase(this->blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::getAllBlocks(){
    return {
        IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()
    };
}

void Game::handleInput(){
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
        case KEY_LEFT:
            this->moveBlockLeft();
            break;
        case KEY_RIGHT:
            this->moveBlockRight();
            break;
        case KEY_DOWN:
            this->moveBlockDown();
            this->isUserInput = true;
            break;
        case KEY_SPACE:
            this->moveBlockFastDown();
            break;
        case KEY_UP:
            this->rotateBlock();
            break;
        default:
            this->isUserInput = false;
    }
}

void Game::update(){
    double currentTime = GetTime();
    if(this->isUserInput){
        this->lastUpdate = 0;
    }else{
        if(currentTime-this->lastUpdate > this->sleepFallTime){
            this->moveBlockDown();
            this->lastUpdate = currentTime;
        }
    }

    if(this->isBlockOutside() || this->isBlockCollide()){
        if(this->nextX!=0 || this->nextY!=0){
            //deshacemos el movimiento.
            this->currentBlock.move(this->nextY*-1, this->nextX*-1);

            //Si es hacia abajo hemos llegado al final.
            if(this->nextX==0 && this->nextY==1){
                this->lockBlock();
                this->currentBlock = this->nextBlock;
                this->nextBlock = this->getRandomBlock();
                this->sleepFallTime = 0.200;

                //Verificar filas llenas.
                this->moveRowsDown();
            }
        }else{
            this->currentBlock.undoRotate();
        }
    }
}

void Game::draw(){
    this->grid.draw();
    this->currentBlock.draw();

    //this->grid.print();
}


/*===========================================================================*/
/*                           Private Section                                 */
/*===========================================================================*/
void Game::moveBlockLeft(){
    this->nextX = -1;
    this->nextY = 0;
    this->currentBlock.move(0,-1);
    this->isUserInput = true;
}

void Game::moveBlockRight(){
    this->nextX = 1;
    this->nextY = 0;
    this->currentBlock.move(0,1);
    this->isUserInput = true;
}

void Game::moveBlockDown(){
    this->nextX = 0;
    this->nextY = 1;
    this->currentBlock.move(1, 0);
}

void Game::moveBlockFastDown(){
    this->nextX = 0;
    this->nextY = 1;
    this->sleepFallTime = 0;
    this->isUserInput = true;
}

void Game::rotateBlock(){
    this->nextX = 0;
    this->nextY = 0;
    this->currentBlock.rotate();
    this->isUserInput = true;
}

bool Game::isBlockOutside(){
    bool isOutside = false;
    std::vector<Position> tiles = this->currentBlock.getCellPositions();
    for(Position item:tiles){
        if(this->grid.isCellOutside(item.row, item.column)){
            isOutside = true;
            break;
        }
    }
    return isOutside;
}

void Game::lockBlock(){
    std::vector<Position> tiles = this->currentBlock.getCellPositions();
    for(Position item:tiles){
        this->grid.grid[item.row][item.column] = this->currentBlock.id;
    }
}

bool Game::isBlockCollide(){
    bool isCollide = false;
    std::vector<Position> tiles = this->currentBlock.getCellPositions();
    for(Position item:tiles){
        if(!this->grid.isCellEmpty(item.row, item.column)){
            isCollide = true;
            break;
        }
    }
    return isCollide;
}

void Game::moveRowsDown(){
    this->grid.moveRowsDown();
}
