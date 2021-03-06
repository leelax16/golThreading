#include "cell.h"
#include <stdexcept>



using namespace std;

Cell::Cell(int x, int y){
    this->x = x;
    this->y = y;
    this->live = 0;
    this->nbrs = 0; 
    this->checked = 0;

}


int Cell::getx(){
    return this->x;
}

int Cell::gety(){
    return this->y;
}

int Cell::getNbrs(){
    return this->nbrs;
}

int Cell::isAlive(){
    return this->live;  
}

void Cell::setLive(){
    this->live = 1;
}

void Cell::setNbr(int count){
    this->nbrs = count;
}

void Cell::addNbr(){
    this->nbrs+=1;
}

void Cell::reset(){
    this->nbrs = 0;
    this->live = 0;
}

void Cell::resetNbr(){
    this->nbrs = 0;
}