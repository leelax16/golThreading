

class Cell{
    private:
        int x, y, nbrs;
        bool live;

    public:
        Cell(int x, int y);
        ~Cell();
        int getx();
        int gety();
        bool isAlive();
        //adds 1 to neighbor count
        void addNbr();
        //sets cell alive
        void setLive();
        //resets neighbor count to 0
        void reset();


};