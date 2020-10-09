#include"DeleteLine.h"
#include"DrawTiles.h"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
extern int gameField[22][12];
extern int score;

void checkFullLine(RenderWindow &window) {

	for (int k = 0; k < 4; k++) {
		for (int i = 20; i >= 1; i--) {
			if (gameField[i][1] && gameField[i][2] && gameField[i][3] && gameField[i][4] && gameField[i][5] &&
				gameField[i][6] && gameField[i][7] && gameField[i][8] && gameField[i][9] && gameField[i][10]) {
				std::cout << "Full" << std::endl;
				deleteLine(window, i);
				score += 100;
				drawTiles(window);
			}
		}
	}
}

void deleteLine(RenderWindow &window, int i) {
	
	for (int j = 1; j <= 9; j++) gameField[i][j] = 0;
	drawTiles(window);

	for (i; i >= 2; i--) {
		for (int j = 1; j <= 10; j++)
			gameField[i][j] = gameField[i - 1][j];
	}
}
