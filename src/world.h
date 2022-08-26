#pragma once
#ifndef WORLD_H
#define WORLD_H
#include <deque>
#include <vector>
#include <iostream>
//#include "cell.h"
//#include "thread_util.h"
using namespace std;

struct cell
{
    int x,y; //position
    int live; // is alive
    int nbrs; //number of live neighbors
    bool checked; //if it has been checked by the get neighbors
};

class World{
    public:
        //vector<cell> a;

        vector<cell*> nextAlive;
        vector<cell*> resets;




        vector<cell*> alive;
        int rows;
        int cols;
        vector<cell> board;
        World(int rows, int cols);
        ~World();
        int getRows();
        int getCols();
        void getNeighbors(int x, int y);
        void checkAlive(int x, int y);
        void play(int start, int end);
        void cleanup(int start, int end);
        void setAlive(int start, int end);
        void transfer();
        void setCell(int x, int y);
        



        

};

#endif