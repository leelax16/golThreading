/*******************************************************************************
 * GOL THREADING PROJECT                                        Created 6/16/22
 * 
 * This is a personal project for me to practice threading using C++. This 
 * project is based on some coursework I did at Swarthmore where he built a GOL
 * simulator using C and pthread libraries. I am also trying to practice 
 * using graphics libraries and my target is to learn SDL2.
 * 
 ******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <windows.h>
#include <chrono>

//#include <SDL2/SDL.h>

#include "map.h"

using namespace std;


void printBoard(Map map) {
cout << "inPrintBoard" << endl;
  /* Print the round number. */
//  fprintf(stderr, "Round: %d\n");

  for (int i = 0; i < map.rows; i++) {
    for (int j = 0; j < map.cols; j++) {
      cout << map.world[i][j]->getx() << map.world[i][j]->gety() << " " ;
    }
    cout << endl;
  }

  for (int i = 0; i < map.rows; i++) {
    for (int j = 0; j < map.cols; j++) {
      //cout << map.world[i][j]->getx() << map.world[i][j]->gety() << " " ;
      if (map.world[i][j]->isAlive()==1){
        cout << "@";
      }
      else{
        cout << ".";
      }
      cout << " ";

    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
}

int main(){
  //vector<vector<int>> a = {{1,2},{2,2},{3,2}};
  Map map = Map(5, 5);
  cout << endl;
  //int i = 0;
  /*
  while (1==1){
    cout << endl << "iteration:" << i << endl << endl;
    //map.play();

    i++;
  }*/
  printBoard(map);
  printf("out of first one");
  printBoard(map);
  cout << endl;
  map.play();
  printBoard(map);


  return 0;
}

//class for the game fucntions

// initialization function

//initialization for window

//fucntion to incoroporate window with game map and fucntions
