#include"GameOver.h"
#include<fstream>

extern bool gameOver;
extern int gameField[22][12];
extern int score;

void checkGameOver() {

	if (gameField[1][4] || gameField[1][5] || gameField[1][6]) {
	gameOver = true;

	int hs;
	std::ifstream hfin("highscore.txt");
	hfin >> hs;
	hfin.close();

	if (hs < score) {
		std::ofstream hfout("highscore.txt");
		hfout << score;
		hfout.close();
	}

	}

}