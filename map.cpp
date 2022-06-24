#include "map.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;



//constructor
//need to input an alive list 
Map::Map(int rows, int cols){
    cout<< "constructor" << endl;
    /*struct cell{
        int x = 0;
        int y = 0;
        int nbrs = 0;
        bool live = false;
    };*/
    this->rows = rows;
    this->cols = cols;
    
    //this->world;

    
    world = new Cell**[rows];
    for(int  i = 0; i < rows; ++i){
        this->world[i] = new Cell*[cols];
        for(int  j = 0; j < cols; ++j){
            //cout << "here" << i << j << endl;
            this->world[i][j] = new Cell(i,j);
        }
    }

/*
    vector<Cell *> w;
    for (int i=0; i < this -> rows; i++){
        for (int j=0; j < this -> cols; j++){
            Cell *n = new Cell(i,j);
            w.push_back(n);
            cout << "here" << i << j << endl;
        }
        this->world.push_back(w);
        w.clear();
    }
*/
    //cout << this->world[0].size() << endl;
    this->alive;
    this->alive.push_back(this->world[1][2]);
    this->alive.push_back(this->world[2][2]);
    this->alive.push_back(this->world[3][2]);
    this->world[1][2]->setLive();
    this->world[2][2]->setLive();
    this->world[3][2]->setLive();
    this->nextBoard;
    this->res;
}

//destructor

Map::~Map(){
    printf("problem\n");
    
    for (int i=0; i < this -> rows; i++){
        for (int j=0; j < this -> rows; j++){
            delete world;
            }
        //delete[] this -> world[i];
    }
    //delete[] this-> world;
}

int Map::get_rows(){
    return this->rows;
}

int Map::get_cols(){
    return this->cols;
}

void Map::checkNeighbors(int i, int j){
    //cout << "in checkNeighbors " <<i << j<< endl;
    int l,r,a,b;
    int count = 0;
    //locating position on board to determine if we need to wrap aroud world
    if(j==0){ //left edge
        l=this->cols-1;
        r=j+1;
    }
    else if(j==this->cols-1){ //right edge
        l=j-1;
        r=0;
    }
    else{ //normal case
        l=j-1;
        r=j+1;
    }

    if(i==0){//top edge
        a = this->rows-1;
        b = i+1;
    }
    else if(i==this->rows-1){ //bottom edge
        a = i-1;
        b = 0;
    }
    else{ //normal case
        a = i-1;
        b = i+1;
    }
/*
    count = count + this->world[a][l]->isAlive(); //top left
    count = count + this->world[a][j]->isAlive(); //above
    count = count + this->world[a][r]->isAlive(); //top right
    count = count + this->world[b][l]->isAlive(); //below left
    count = count + this->world[b][j]->isAlive(); //below
    count = count + this->world[b][r]->isAlive(); //below right
    count = count + this->world[i][l]->isAlive(); //left
    count = count + this->world[i][l]->isAlive(); //right
*/

    int hz[3] = {a,b,i};
    int vt[3] = {l,r,j};
    if (this->world[i][j]->isAlive()){
        for (int g=0; g<3; g++){
            for (int h=0; h<3; h++){
                if (!this->world[hz[g]][vt[h]]->isAlive() && this->world[hz[g]][vt[h]]->getNbrs()!=0){
                    checkNeighbors(hz[g], vt[h]);
                }
                else{
                    count++;
                }
            }
        }
        count--;
    }
    else{
        for (int g=0; g<3; g++){
            for (int h=0; h<3; h++){
                if (this->world[hz[g]][vt[h]]->isAlive()){
                    count++;
                }
            }
        }
    }
        
    this->world[i][j]->setNbr(count);

    int c = this->world[i][j]->getNbrs();
    if (this->world[i][j]->isAlive()==1){ //if the cell is alive
       this->nextBoard.push_back(this->world[i][j]);
    }

    else{ //cell ded
        if (c==3){ 
            this->res.push_back(this->world[i][j]);
        }
    }
}
    

void Map::play(){
    for (int i=0; i < this -> rows; i++){
        for (int j=0; j < this -> cols; j++){
            checkNeighbors(i,j);
        }        
    }
    for (int i; i<this->nextBoard.size(); i++){
        if (!this->nextBoard[i]->isAlive()){
            this->nextBoard[i]->setLive();
        }
    }
    this->alive = this->nextBoard;
    for (int i; i<this->res.size();i++){
        //printf("line 173 while\n");
        this->res[0]->reset();
    }
    printf("out fo while\n");
    this->res.clear();
    


    
}
