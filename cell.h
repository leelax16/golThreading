#pragma once
#include <string.h>

class Cell{
    private:
        int x, y;
        int nbrs;



    public:
        bool live;
        bool checked;
        Cell(int x, int y);
        Cell();
        int getx();
        int gety();
        int getNbrs();
        //checks if live variable is 1
        int isAlive();
        //sets the nbr value
        void setNbr(int count);
        //adds 1 to neighbor count
        void addNbr();
        //sets cell alive
        void setLive();
        //resets neighbor count to 0
        void reset();

        void resetNbr();

        //temp functions to test in terminal

};