#include "block.hpp"

class LBlock:public Block {
    public:
        LBlock(){
            this->id = 1;
            //Rotaciones de la ficha.
            this->cells[0] = {
                Position(0,2),
                Position(1,0),
                Position(1,1),
                Position(1,2)
            };
            this->cells[1] = {
                Position(0,1),
                Position(1,1),
                Position(2,1),
                Position(2,2)
            };
            this->cells[2] = {
                Position(1,1),
                Position(1,2),
                Position(1,3),
                Position(2,1)
            };
            this->cells[3] = {
                Position(0,0),
                Position(0,1),
                Position(1,1),
                Position(2,1)
            };
        }
};


class JBlock:public Block {
    public:
        JBlock(){
            this->id = 2;
            this->cells[0] = {
                Position(0,0),
                Position(1,0),
                Position(1,1),
                Position(1,2)
            };
            this->cells[1] = {
                Position(0,1),
                Position(0,2),
                Position(1,1),
                Position(2,1)
            };
            this->cells[2] = {
                Position(1,0),
                Position(1,1),
                Position(1,2),
                Position(2,2)
            };
            this->cells[3] = {
                Position(0,1),
                Position(1,1),
                Position(2,0),
                Position(2,1)
            };
        }
};

class IBlock:public Block {
    public:
        IBlock(){
            this->id = 2;
            this->cells[0] = {
                Position(1,0),
                Position(1,1),
                Position(1,2),
                Position(1,3)
            };
            this->cells[1] = {
                Position(0,2),
                Position(1,2),
                Position(2,2),
                Position(3,2)
            };
            this->cells[2] = {
                Position(2,0),
                Position(2,1),
                Position(2,2),
                Position(2,3)
            };
            this->cells[3] = {
                Position(0,1),
                Position(1,1),
                Position(2,1),
                Position(3,1)
            };
        }
};

class OBlock:public Block {
    public:
        OBlock(){
            this->id = 3;
            this->cells[0] = {
                Position(0,0),
                Position(0,1),
                Position(1,0),
                Position(1,1)
            };
            this->cells[1] = this->cells[0];
            this->cells[2] = this->cells[0];
            this->cells[3] = this->cells[0];
        }
};

class SBlock:public Block {
    public:
        SBlock(){
            this->id = 4;
            this->cells[0] = {
                Position(0,1),
                Position(0,2),
                Position(1,0),
                Position(1,1)
            };
            this->cells[1] = {
                Position(0,1),
                Position(1,1),
                Position(1,2),
                Position(2,2)                
            };
            this->cells[2] = {
                Position(1,1),
                Position(1,2),
                Position(2,0),
                Position(2,1)
            };
            this->cells[3] = {
                Position(0,0),
                Position(1,0),
                Position(1,1),
                Position(2,1)
            };
        }
};

class TBlock:public Block {
    public:
        TBlock(){
            this->id = 5;
            this->cells[0] = {
                Position(0,1),
                Position(1,0),
                Position(1,1),
                Position(1,2)
            };
            this->cells[1] = {
                Position(0,1),
                Position(1,1),
                Position(1,2),
                Position(2,1)
            };
            this->cells[2] = {
                Position(1,0),
                Position(1,1),
                Position(1,2),
                Position(2,1)
            };
            this->cells[3] = {
                Position(0,1),
                Position(1,0),
                Position(1,1),
                Position(2,1)
            };
        }
};

class ZBlock:public Block {
    public:
        ZBlock(){
            this->id = 6;
            this->cells[0] = {
                Position(0,0),
                Position(0,1),
                Position(1,1),
                Position(1,2)
            };
            this->cells[1] = {
                Position(0,2),
                Position(1,1),
                Position(1,2),
                Position(2,1)
            };
            this->cells[2] = {
                Position(1,0),
                Position(1,1),
                Position(2,1),
                Position(2,2)
            };
            this->cells[3] = {
                Position(0,1),
                Position(1,0),
                Position(1,1),
                Position(2,0)
            };
        }
};
