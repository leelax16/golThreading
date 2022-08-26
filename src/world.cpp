#include "world.h"
using namespace std;

World::World(int rows, int cols)     
    : board((rows*cols),cell())
    {

    this->rows = rows;
    this->cols = cols;
    

    for (int x = 0; x < this->rows; x++){
        for (int y = 0; y < this->cols; y++){
            this->board[(x*cols) + y].x = x;
            this->board[(x*cols) + y].y = y;
            this->board[(x*cols) + y].live = 0;
            this->board[(x*cols) + y].checked = 0;
        }
    }
/*
    this->alive.push_back(&this->board[11]);
    this->board[11].live = 1;
    this->alive.push_back(&this->board[17]);
    this->board[17].live = 1;
    this->alive.push_back(&this->board[2]);
    this->board[2].live = 1;
    this->alive.push_back(&this->board[18]);
    this->board[18].live = 1;
    this->alive.push_back(&this->board[19]);
    this->board[19].live = 1;   
*/
/*
    this->alive.push_back(&this->board[203]);
    this->board[203].live = 1;
    this->alive.push_back(&this->board[202]);
    this->board[202].live = 1;
    this->alive.push_back(&this->board[2]);
    this->board[2].live = 1;
    this->alive.push_back(&this->board[103]);
    this->board[103].live = 1;
    this->alive.push_back(&this->board[201]);
    this->board[201].live = 1;    
    */
   /*
    this->alive.push_back(&this->board[80]);
    this->board[80].live = 1;
    this->alive.push_back(&this->board[280]);
    this->board[280].live = 1;
    this->alive.push_back(&this->board[279]);
    this->board[279].live = 1;
    this->alive.push_back(&this->board[478]);
    this->board[478].live = 1;
    this->alive.push_back(&this->board[477]);
    this->board[477].live = 1;    
    this->alive.push_back(&this->board[476]);
    this->board[476].live = 1;
    this->alive.push_back(&this->board[675]);
    this->board[675].live = 1;
    this->alive.push_back(&this->board[677]);
    this->board[677].live = 1;
    this->alive.push_back(&this->board[676]);
    this->board[676].live = 1;
    this->alive.push_back(&this->board[776]);
    this->board[776].live = 1;
    */
}


World::~World(){

}

/*finds neighbors fo current cell*/
void World::getNeighbors(int x, int y){
    this->board[(x*cols) + y].checked = 1;
    int l,r,a,b;
    //locating position on board to determine if we need to wrap aroud world
    if(x==0){ //left edge
        l=this->cols-1;
        r=x+1;
    }
    else if(x==this->cols-1){ //right edge
        l=x-1;
        r=0;
    }
    else{   //normal case
        l=x-1;
        r=x+1;
    }

    if(y==0){   //top edge
        a = this->rows-1;
        b = y+1;
    }
    else if(y==this->rows-1){   //bottom edge
        a = y-1;
        b = 0;
    }
    else{ //normal case
        a = y-1;
        b = y+1;
    }
    

    int hz[3] = {l,r,x};
    int vt[3] = {a,b,y};

    if (this->board[(x*cols) + y].live){
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (this->board[(hz[i]*this->cols) + vt[j]].live){
                    this->board[(x*cols) + y].nbrs++;
                }
                else if(!this->board[(hz[i]*this->cols) + vt[j]].checked){
                    getNeighbors(hz[i], vt[j]);
                }
            }
        }
        this->board[(x*cols) + y].nbrs--;
    }
    else{
        for (int i = 0; i<3; i++){
            for (int j = 0; j<2; j++){
                if (this->board[(hz[i]*this->cols) + vt[j]].live){
                    this->board[(x*cols) + y].nbrs++;
                }
            }
        }
        for (int i = 0; i<2; i++){//to skip checking itself
            if (this->board[(hz[i]*this->cols) + vt[2]].live){
                this->board[(x*cols) + y].nbrs++;
            }
        }
    }
    checkAlive(x,y);
    this->board[(x*cols) + y].nbrs = 0;
    }

//GOL basic rules
void World::checkAlive(int x, int y){
    int count = this->board[(x*cols) + y].nbrs;
    if (count==2 && this->board[(x*cols) + y].live==1){ //if the cell is alive
        this->nextAlive.push_back(&this->board[(x*cols) + y]);
    }
    else if (count ==3){ //cell ded and has exactly three neighbors, alive
        this->nextAlive.push_back(&this->board[(x*cols) + y]);
    }
    else{
        this->resets.push_back(&this->board[(x*cols) + y]);
    }
}


//central fucntion to handle background game data mechanics
void World::play(int start, int end){
    //all threads start
    //partition here
    for (int i = start; i<=end; i++){
        getNeighbors(this->alive[i]->x, this->alive[i]->y);
    }

    //all threads need to wait
    //once all threads finish neighbors, move onto while loop
}

void World::cleanup(int start, int end){
    for (int i = start; i<=end; i++){
        this->resets[i]->live = 0;
        this->resets[i]->checked = 0;
    }
    //join threads after all threads cleanup
//    this->alive = this->nextAlive;
 //   this->nextAlive.clear();
}

void World::transfer(){
    //cout << "here" << this->resets.size()<<endl;
    this->alive = this->nextAlive;
    this->nextAlive.clear();
    this->resets.clear();
}

void World::setAlive(int start,int end){
    for (int i = 0; i<this->alive.size(); i++){
        this->alive[i]->live = 1;
    }
}

void World::setCell(int x, int y){

}
