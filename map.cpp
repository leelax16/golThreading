#include "map.h"

Map::Map(int rows, int cols){
    this -> rows = rows;
    this -> cols = cols;
     
    for (int i;i<this->rows;i++){
        this -> world.push_back(i);
    }
