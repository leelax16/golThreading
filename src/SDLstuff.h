
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "world.h"
#include "threadUtil.h"
#include <iostream>
#include <stdio.h>
#include <vector>
extern int rows;
extern int cols;

class disp{
    public:
        TTF_Font *coda;
        SDL_Window *window;
        SDL_Renderer *rend;
        int rWidth;
        int rHeight;
        bool is_running;
        bool pause;
        int mx;
        int my;
        World *w;
        int xOffset;
        int yOffset;
        bool runMenu;
        disp(int rows, int cols, World *w);
        ~disp();
        void mainLoop(int rows, int cols);
        bool screeninit();
        void menu();
        void drawCells(SDL_Rect rects[]);
        
        void handleInput(SDL_Event e, SDL_Rect *rects);
        void end();

};


