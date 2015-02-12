/**
 * main.cpp
 *
 * 	Main entry point for application.
 *  
 */

#include <iostream>
#include "Game.h"

using namespace std;

Game* game = new Game();

int main(int arc, char** argv) 
{
  game->Init();
  game->Loop();
  game->CleanUp();
}
