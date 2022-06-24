#pragma once
#include <queue>
#include <vector>
#include "cell.h"
using namespace std;




class Map{
    private:
        //struct cell;

        vector<Cell*> alive;
        vector<Cell*> nextBoard;
        vector<Cell*> res;





    public:
        int rows;
        int cols;
        //vector<vector<Cell*>> world;
        Cell*** world;
        //constructor creating a map with the correct number fo rows and cols
        Map(int rows, int cols);

        //destructor
        ~Map();

       // void init_alive();
        //getter for rows
        int get_rows();

        //getter for cols
        int get_cols();

        int getCell(int i, int j);
        //function to find neigbors of a cell
        void checkNeighbors(int i, int j);

        //Plays gol each round to update board and return a vector of living cells
        void play();


        

        

}; 