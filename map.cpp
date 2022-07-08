#include "map.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;




Map::Map(int cols, int rows){
    this -> cols = cols;
    this ->rows = rows;
    struct cell{
        int x;
        int y;
        int live = 0;
    };
    cell board[rows*cols];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j <cols; j++){
            board[(i*this->cols) + j].x = j;
            board[(i*this->rows) + i].y = i;
        }
    }
}

Map::~Map(){
}

void Map::play(){
    for (int i = 0; i<this->alive.size(); i++){
        
    }
}





/*
//constructor
//need to input an alive list 
Map::Map(int cols, int rows){
    cout<< "constructor" << endl;
    this->rows = rows;
    this->cols = cols;
    world = new Cell**[cols];
    for(int x = 0; x < rows; ++x){
        this->world[x] = new Cell*[rows];
        for(int y = 0; y < cols; ++y){
            //cout << "here" << i << j << endl;
            this->world[x][y] = new Cell(x,y);
        }
    }

    //cout << this->world[0].size() << endl;
    //this->alive;
    //this->alive.push_back(this->world[1][0]);
    //this->alive.push_back(this->world[2][1]);
    this->alive.push_back(this->world[2][2]);
    this->alive.push_back(this->world[1][2]);
    this->alive.push_back(this->world[0][2]);  
    for (int i=0; i<this->alive.size(); i++) {
        this->alive[i]->setLive();
    }



}

//destructor

Map::~Map(){
    printf("problem\n");
    
    for (int i=0; i < this -> rows; i++){
        for (int j=0; j < this -> rows; j++){
            delete world[i][j];
            }
        delete[] this -> world[i];
    }
    delete[] this-> world;
}

int Map::get_rows(){
    return this->rows;
}

int Map::get_cols(){
    return this->cols;
}

void Map::checkNeighbors(Cell* curr){
    //cout << "in checkNeighbors " <<i << j<< endl;
    int x = curr->getx();
    int y = curr->gety();

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
    else{ //normal case
        l=x-1;
        r=x+1;
    }

    if(y==0){//top edge
        a = this->rows-1;
        b = y+1;
    }
    else if(y==this->rows-1){ //bottom edge
        a = y-1;
        b = 0;
    }
    else{ //normal case
        a = y-1;
        b = y+1;
    }
    //figure out neighbors
    int hz[3] = {a,b,y};
    int vt[3] = {l,r,x};
    cout << "at " << y << x << endl;

//alives have check == 1
//add 1 to each nbr and that nbr check == 0, set chekc = 1 and add to vector checks

    if (curr->isAlive()==0){
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (this->world[hz[i]][vt[j]]->isAlive()){
                    curr->addNbr();
                }
            }
        }
    }
    else{
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (this->world[hz[i]][vt[j]]->isAlive()){
                    curr->addNbr();
                }
                else if(this->world[hz[i]][vt[j]]->checked == 0){
                    this->checks.push_back(this->world[hz[i]][vt[j]]);
                }
            }
        }
    }
}



void Map::rule(Cell* curr){
    int count = curr->getNbrs();
    if (curr->live==1){ //if the cell is alive
        if (count>1 && count<4){ //does it have 2 or 3 neighbors
            this->nextAlive.push_back(curr);
            curr->setLive();
        }
        else{//if not kill it
            curr->reset();
        }

    }
       

    else{ //cell ded
        if (count==3){ //if it has exactly three neighbors its alive now
            curr->setLive();
            this->nextAlive.push_back(curr);
        }
    }
    curr->resetNbr();
}

    

void Map::play(){
    for (int i = 0; i<this->alive.size(); i++){
        checkNeighbors(this->alive[i]);
    }
    
    for (int i = 0; i<this->checks.size(); i++){
        checkNeighbors(this->checks[i]);
    }
    //this->nextAlive.clear();
    for (int i = 0; i<this->checks.size(); i++){
        rule(this->checks[i]);
    }  
    cout << endl << "alive: " << this->alive.size() << endl;
    cout << "nextAlive: " << this->nextAlive.size() << endl;
    cout << "checks " << this->checks.size() << endl;    
}


void Map::printBoard() {
//cout <<"for loop 2 \n";
cout << this->world[2][3]->getNbrs() <<endl
;
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->cols; j++) {
      //cout << map.world[i][j]->getx() << map.world[i][j]->gety() << " " ;
      if (this->world[i][j]->live==1){
        cout << "@";
      }
      else{
        cout << ".";
      }
      cout << " ";

    }
    cout << endl;
  }
}
*/