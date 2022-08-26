/*******************************************************************************
 * GOL THREADING PROJECT                                        Created 6/16/22
 * 
 * This is a personal project for me to practice threading using C++. This 
 * project is based on some coursework I did at Swarthmore where he built a GOL
 * simulator using C and pthread libraries. I am also trying to practice 
 * using graphics libraries and my target is to learn SDL2.
 * 
 ******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>

#include "src/world.h"
#include "src/SDLstuff.h"
//#include "thread_util.h"

/*
static int shader(const std::string& vertexShader, const std::string& fragmentShader){
  
}
*/
//#include <stack>
//#include <windows.h>
//#include <chrono>
//static int max_threads = 4;//std::thread::hardware_concurrency();

using namespace std;





//mutex m;
//condition_variable cond1, cond2;

SDL_Window *window = NULL;
SDL_Renderer *renderer;
int rWidth;
int rHeight;
bool is_running;

 
void printBoard(World w,int rows, int cols){
  for (int i = 0; i<rows; i++){
    for (int j = 0; j<cols; j++){
      //printf("pos: %d , %d \n", i, j);
      //printf("%d %d\n",w.board[i][j].x,w.board[i][j].y);
      if (w.board[(i*w.cols) + j].live){
        printf("@");
      }
      else{
        printf(".");
      }
    } 
    cout << endl;

  }
}

int rows = 100;
int cols = 100;

int main(int argc, char **argv){
   
  World w = World(rows,cols);

  disp d = disp(rows, cols, &w);
  d.mainLoop(rows, cols);

/*
  
  printf("max threads: %d\n", max_threads);
 
  //World w = World(8,8);
  for (int f = 0; f<10; f++){ 
    cout << "round " << f << endl;
    printBoard(w,rows,cols);
    cout << w.alive.size() << endl;
    if (max_threads<w.alive.size()){
      main_thread_func(&w);
      //create_thread(max_threads, w);
    }
    else{
      printf("wasnt bigger\n");
    }
    system("cls");
    //w.play();
    cout << endl;
    
  } 

  

*/

  return 0;
}






//class for the game fucntions

// initialization function

//initialization for window


