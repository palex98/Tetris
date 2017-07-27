#include <SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
#include"matrix.h"
using namespace sf;

  int gameField[22][12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
							1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

  void newGame() {
	  for (int i = 1; i < 21; i++)
		  for (int j = 1; j < 11; j++)
			  gameField[i][j] = 0;
 }