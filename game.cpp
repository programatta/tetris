#include "game.hpp"
#include <random>
#include "blocks.cpp"


Game::Game(){
    this->grid = Grid();
    this->blocks = this->getAllBlocks();
    this->currentBlock = this->getRandomBlock();
    this->nextBlock = this->getRandomBlock();
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
            break;
        case KEY_UP:
            this->rotateBlock();
    }
}

void Game::update(){
    if(this->isBlockOutside()){
        if(this->nextX!=0 || this->nextY!=0){
            //deshacemos el movimiento.
            this->currentBlock.move(this->nextX*-1, this->nextY*-1);
        }else{
            this->currentBlock.undoRotate();
        }
    }

    this->nextX = 0;
    this->nextY = 0;
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
    this->nextX = 0;
    this->nextY = -1;
    this->currentBlock.move(0,-1);
}

void Game::moveBlockRight(){
    this->nextX = 0;
    this->nextY = 1;
    this->currentBlock.move(0,1);
}

void Game::moveBlockDown(){
    this->nextX = 1;
    this->nextY = 0;
    this->currentBlock.move(1, 0);
}

void Game::rotateBlock(){
    this->currentBlock.rotate();
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
