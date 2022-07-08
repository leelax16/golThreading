#pragma once
#include <queue>
#include <vector>
#include "cell.h"
using namespace std;




class Map{
    private:
        struct cell;
        

        vector<Cell*> alive;
        vector<Cell*> nextAlive;
        vector<Cell*> checks;





    public:
        int rows;
        int cols;
        //vector<vector<Cell*>> world;
        Cell*** world;
        //constructor creating a map with the correct number fo rows and cols
        Map(int cols, int rows);

        //destructor
        ~Map();

       // void init_alive();
        //getter for rows
        int get_rows();

        //getter for cols
        int get_cols();

        int getCell(int i, int j);
        //function to find neigbors of a cell
        void checkNeighbors(Cell* curr);

        void rule(Cell* curr);
        //Plays gol each round to update board and return a vector of living cells
        void play();

        void printBoard();


        

        

}; 