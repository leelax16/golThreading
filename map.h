#include "cell.h"
#include <vector>
using namespace std;


class Map{
    private:
        int rows;
        int cols;
        vector<Cell> *alive;
        vector<Cell> *prevlive;
        vector<vector<Cell>> world;



    public:
        //constructor creating a map with the correct number fo rows and cols
        Map(int rows, int cols);

        //destructor
        ~Map();

        //getter for rows
        int get_rows();

        //getter for cols
        int get_cols();

        //function to find neigbors
        void Neighbors();

        //sets new alive and turns old alive to 0
        void update();
        

        

};